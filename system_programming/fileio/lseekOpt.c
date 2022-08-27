/*************************************************************************
	> File Name: lseekOpt.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Apr 2022 02:20:02 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int fd = open("./kaikeba.txt", O_RDONLY);
    if (fd < 0) {
        perror("OPEN");
        exit(1);
    }
    
    char c;
    read(fd, &c, 1);
    write(STDOUT_FILENO, &c, 1);
    int pos = lseek(fd, 3, SEEK_CUR);
    read(fd, &c, 1);
    write(STDOUT_FILENO, &c, 1);
    printf("pos = %d\n", pos);

    //int pos = lseek(fd, 0, SEEK_END);
   // printf("pos = %d\n", pos);
    close(fd);

    return 0;
}
