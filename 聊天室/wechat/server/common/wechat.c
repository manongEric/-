/*************************************************************************
	> File Name: wechat.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 01 Mar 2022 06:47:16 PM CST
 ************************************************************************/

#include "head.h"
struct wechat_user *users;
int add_to_reactor(int epollfd, int fd){
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN | EPOLLET;
    make_nonblock(fd);

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        return -1;
    }
    return 0;
}
void send_all(struct wechat_msg *msg) {
    for (int i = 0; i < MAXUSERS; i++) {
        if (users[i].isOnline && strcmp(users[i].name, msg->from)) {
            send(users[i].fd, msg, sizeof(msg), 0);
        }
    }
}

void *sub_reactor(void *arg) {
    int subfd = *(int *)arg;
    DBG(L_RED"<Sub Reactor>"NONE" : in sub reactor %d.\n", subfd);
    
    struct epoll_event ev, events[MAXEVENTS];
    for (;;) {
        int nfds = epoll_wait(subfd, events, MAXEVENTS, -1);
        if (nfds < 0) {
            DBG(L_RED"<Sub Reactor, Err> : sub reactor error %d.\n", subfd);
            continue;
        }
        //不需要管理 listenfd ，注册信息
        for (int i = 0; i < nfds; i++) {
            int fd = events[i].data.fd;
            struct wechat_msg msg;
            bzero(&msg, sizeof(msg));
            int ret = recv(fd, (void *)&msg, sizeof(msg), 0);
            if (ret <= 0 && errno != EAGAIN)  {
                close(fd);
                epoll_ctl(subfd, EPOLL_CTL_DEL, fd, NULL);
                users[fd].isOnline = 0;
                DBG(L_RED"<Sub Reactor, Err> : connection of  %d on %d is closed.\n"NONE, fd, subfd);
                continue;
            }
            if (ret != sizeof(msg)) {
                DBG(L_RED"<Sub Reactor Err> : meg size error\n"NONE);
                continue; 
            }
            if (msg.type & WECHAT_WALL) {
                DBG(BLUE"%s : %s\n", msg .from, msg.msg);
                send_all(&msg);
            }
        }
    }
}


void *client_recv(void *arg) {
    int sockfd = *(int *)arg;
    struct wechat_msg msg;
    while (1) {
        bzero(&msg, sizeof(msg));
        int ret = recv(sockfd, &msg, sizeof(msg), 0);
        if (ret <= 0) {
            DBG(RED"<Err>"NONE" : server closed connection \n");
            perror("recv");
            exit(1);
        }
        printf("%s : %s\n", msg.from, msg.msg);
    }
}
