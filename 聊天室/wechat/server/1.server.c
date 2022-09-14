/*************************************************************************
	> File Name: 1.server.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 01 Mar 2022 06:03:30 PM CST
 ************************************************************************/

#include "head.h"

const char *config = "./wechatd.conf";
struct wechat_user *users;

int main(int argc, char **argv) {
    int opt, port = 0, server_listen, sockfd, epollfd, subefd1, subefd2;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
                port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -p port.\n", argv[0]);
                exit(1);
        }
    }
   
    if (access(config, R_OK)) {
        fprintf(stderr, RED"<Error>"NONE"config file error!\n");
        exit(1);
    }

    if (!port) {
        //读配置文件
        port = atoi(get_conf_value(config, "PORT"));
        DBG("port = %d!\n", port);
    }
    DBG(YELLOW"<D>"NONE" : config file read success.\n");
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }

    DBG(YELLOW"<D>"NONE" : server_listen is listening on port %d.\n", port);
    
    users = (struct wechat_user *)calloc(MAXUSERS, sizeof(struct wechat_user));

    if ((epollfd = epoll_create(1)) < 0) {
        perror("epoll_create");
        exit(1);
    }
    if ((subefd1 = epoll_create(1)) < 0) {
        perror("epoll_create");
        exit(1);
    }
    if ((subefd2 = epoll_create(1)) < 0) {
        perror("epoll_create");
        exit(1);
    }
    DBG(YELLOW"<D>"NONE" : Main reactor and two sub reactors created.\n");

    pthread_t tid1, tid2;
    DBG(YELLOW"<D>"NONE" : two sub reactor threads created.\n");
    pthread_create(&tid1, NULL, sub_reactor, (void *)&subefd1);
    pthread_create(&tid2, NULL, sub_reactor, (void *)&subefd2);

    struct epoll_event events[MAXEVENTS], ev;
    ev.data.fd = server_listen;
    ev.events = EPOLLIN;

    epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev);

    for (;;) {
        int nfds = epoll_wait(epollfd, events, MAXEVENTS, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            exit(1);
        }
        for (int i = 0; i < nfds; i++) {
            int fd = events[i].data.fd;
            if (fd == server_listen && events[i].events & EPOLLIN) {
                if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
                    perror("accept");
                    exit(1);
                }
                ev.data.fd = sockfd;
                ev.events = EPOLLIN;
                epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev);
            } else {
                //收数据，验证，操作
                struct wechat_msg msg;
                bzero(&msg, sizeof(msg));
                int ret = recv(fd, (void *)&msg, sizeof(msg), 0);
                if (ret <= 0) {
                    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    continue;
                }
                if (ret != sizeof(msg)) {
                    DBG(RED"<MsgErr>"NONE" : msg size err!\n");
                    continue;
                }
                if (msg.type & WECHAT_SIGNUP) {
                    //注册用户,更新用户信息到文件中，判断是否可以注册
                    msg.type = WECHAT_ACK;
                    send(fd, (void *)&msg, sizeof(msg), 0);
                } else if (msg.type & WECHAT_SIGNIN) {
                    //登录，判断密码是否正确，验证用户是否重复登录
                    //加到从反应堆中
                    msg.type = WECHAT_ACK;
                    send(fd, (void *)&msg, sizeof(msg), 0);
                    strcpy(users[fd].name, msg.from);
                    users[fd].fd = fd;
                    users[fd].isOnline = 1;
                    users[fd].sex = msg.sex;
                    int which = msg.sex ? subefd1 : subefd2;
                    add_to_reactor(which, fd);
                } else {
                    //报文数据有误
                }
            }
        }
    }
    sleep(10);
    return 0;
}
