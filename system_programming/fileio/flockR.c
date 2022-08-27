/*************************************************************************
	> File Name: flock.c
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Apr 2022 12:31:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
    int fd = open("./kaikeba.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    
    struct stat sta;
    fstat(fd, &sta);
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_pid = getpid();
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = sta.st_size;

    printf("pid : %d ", lock.l_pid);
    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("fcntl");
        exit(1);
    } else {
        printf("add read lock successfully\n");
    }
    getchar();
    close(fd);
    return 0;
}
