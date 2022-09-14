/*************************************************************************
	> File Name: wechat.h
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 01 Mar 2022 06:47:13 PM CST
 ************************************************************************/

#ifndef _WECHAT_H
#define _WECHAT_H
#define MAXEVENTS 5
#define MAXUSERS 1024
struct wechat_user{
    char name[50];
    char passwd[20];
    int sex;
    int fd;
    int isOnline;
};

#define WECHAT_SIGNUP 0x01
#define WECHAT_SIGNIN 0x02
#define WECHAT_SIGNOUT 0x04
#define WECHAT_ACK 0x08
#define WECHAT_NAK 0x10
#define WECHAT_SYS 0x20
#define WECHAT_WALL 0x40
#define WECHAT_MSG 0x80
#define WECHAT_FIN 0x100
#define WECHAT_HEART 0x200


struct wechat_msg{
    int type;
    int sex;
    char from[50];
    char to[50];
    char msg[1024];
};
void *sub_reactor(void *arg);
void *client_recv(void *arg);
int add_to_reactor(int efd, int fd);
#endif
