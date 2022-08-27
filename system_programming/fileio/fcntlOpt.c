/*************************************************************************
	> File Name: fcntlOpt.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Apr 2022 03:05:39 PM CST
 ************************************************************************/

#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main() {
    int flags;

    if ((flags = fcntl(STDIN_FILENO, F_GETFL)) < 0) {
        perror("fcntl get flags");
        exit(1);
    }
    flags |= O_NONBLOCK;
    if ((flags = fcntl(STDIN_FILENO, F_SETFL, flags)) < 0) {
        perror("fcntl set flags");
        exit(1);
    }
    ssize_t n;
    char buf[20];
    int cnt = 10;
    n = read(0, buf, 10);
    if (n < 0) {
        perror("read");
        exit(1);
    }
   /* while (cnt--) {
        n = read(0, buf, 10);
        if (~n) {
            printf("Read %ld bytes\n", n);
            write(STDOUT_FILENO, buf, n);
           // putchar(10);
            break;
        }
        if (errno != EAGAIN) {
            perror("Read /dev/tty");
            exit(1);
        }

        write(STDOUT_FILENO, "try try\n", 8);
        sleep(1);
    }*/
    return 0;
}
