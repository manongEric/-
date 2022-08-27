/*************************************************************************
	> File Name: fcntlGetStatus.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Apr 2022 04:06:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage : cmd fd\n");
        exit(1);
    }
    int flags;//argv[]记录文件地址， 即文件描述符， atoi将字符串化的地址信息转为整数
    if ((flags = fcntl(atoi(argv[1]), F_GETFL)) < 0) {
        perror("fcntl get flags");
        exit(1);
    }
    //ACC包含读写
    switch(flags & O_ACCMODE) {
        case O_RDONLY :
            printf("read only");
            break;
        case O_WRONLY :
            printf("write only");
            break;
        case O_RDWR :
            printf("read write");
            break;
        default:
            printf("invalid access mode\n");
    }
    if (flags & O_APPEND) {
        printf(", append");
    }
    if (flags & O_NONBLOCK) {
        printf(", nonblock");
    }
    putchar(10);
    return 0;
}
