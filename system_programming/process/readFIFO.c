/*************************************************************************
	> File Name: readFIFO.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Apr 2022 10:01:43 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    char buf[20];

    int fd = open("./tube", O_RDONLY);
    if (fd < 0) {
        perror("OPEN");
        exit(1);
    }

    ssize_t n = read(fd, buf, 20);
    printf("read %ld bytes\n", n);

    write(1, buf, n);

    close(fd);


    return 0;
}
