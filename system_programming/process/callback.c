/*************************************************************************
	> File Name: callback.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Apr 2022 01:43:57 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage : cmd + inputfile + outputfile\n");
        exit(1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open inputfile");
        exit(1);
    }
    dup2(fd, 0);
    close(fd);
    fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("open outfile");
        exit(1);
    }
    dup2(fd, 1);
    close(fd);
    execl("./upper", "./upper", NULL);
    perror("exec");
    exit(1);
} 
