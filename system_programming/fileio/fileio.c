/*************************************************************************
	> File Name: fileio.c
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Apr 2022 07:07:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
    //read 
    /*
    if (argc < 2) {
        printf("usage : cmd filename\n");
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("OPEN");
        exit(3);
    } else {
        perror("OPEN");
    }
    
    char buf[20];
    ssize_t n;
    n = read(fd, buf, 10);
    printf("read %ld bytes\n", n);
    for (int i = 0; i < n; i++) {
        printf("%c", buf[i]);
    }
    printf("\n");
    
    n = read(fd, buf, 10);
    printf("read %ld bytes\n", n);
    for (int i = 0; i < n; i++) {
        printf("%c", buf[i]);
    }
    printf("\n");*/

    //write
    char buf[20];
    int n;
    n = read(STDIN_FILENO, buf, 10);
    if (n < 0) {
        perror("READ");
        exit(1);
    } 
    printf("read %d bytes\n", n);

    write(STDOUT_FILENO, buf, n);
    write(STDOUT_FILENO, "\n", 1);
    //close(fd);
    return 0;
}
