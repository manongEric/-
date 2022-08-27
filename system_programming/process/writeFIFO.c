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

    int fd = open("./tube", O_WRONLY);
    if (fd < 0) {
        perror("OPEN");
        exit(1);
    }

    write(fd, "hello world\n", 12);

    close(fd);


    return 0;
}
