/*************************************************************************
	> File Name: wechat.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 01 Mar 2022 06:47:16 PM CST
 ************************************************************************/

#include "head.h"
#ifndef _CIL
int add_to_reactor(int epollfd, int fd){//增加从反应堆，接下连接好的文件描述符，进行后续操作
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN | EPOLLET;
    make_nonblock(fd);

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        return -1;
    }
    return 0;
}


void *sub_reactor(void *arg) {
    int subfd = *(int *)arg;
    while (1) {
        DBG(L_RED"<Sub Reactor>"NONE" : in sub reactor %d.\n", subfd);
        sleep(30);
    }
}
#endif

void *client_recv(void *arg) {//客户端负责接收服务端线程
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
