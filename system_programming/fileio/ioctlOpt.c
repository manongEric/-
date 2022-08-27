/*************************************************************************
	> File Name: ioctlOpt.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Apr 2022 07:19:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ioctl.h>
int main() {
    struct winsize size;
    
    if (!isatty(1)) {
        printf("1 is not a tty\n");
    }
    
    if (ioctl(1, TIOCGWINSZ, &size) < 0) {
        perror("ioctl");
        exit(1);
    }

    printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
    return 0;
}
