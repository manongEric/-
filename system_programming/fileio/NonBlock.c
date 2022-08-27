/*************************************************************************
	> File Name: NonBlock.c
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Apr 2022 02:31:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("OPEN : /dev/tty");
        exit(1);
    }

    ssize_t n;
    char buf[20];
    int cnt = 10;
    while (cnt--) {
        n = read(fd, buf, 10);
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
    }
    close(fd);

    return 0;
}
