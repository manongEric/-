/*************************************************************************
	> File Name: dupOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Apr 2022 11:24:46 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int fd, save_fd;

    if ((fd = open("./kaikeba.txt", O_RDWR)) < 0) {
        perror("open");
        exit(1);
    }

    save_fd = dup(1);
    dup2(fd, 1);
    close(fd);
    write(1, "1234567890", 10);
    dup2(save_fd, 1);
    write(1, "1234567890", 10);
    close(save_fd);
    return 0;
}
