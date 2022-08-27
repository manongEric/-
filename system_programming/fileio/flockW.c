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
    int fd = open("./kaikeba.txt", O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    
    struct stat sta;
    fstat(fd, &sta);
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_pid = getpid();
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = sta.st_size;

    printf("pid : %d ", lock.l_pid);
    while (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("fcntl");
        struct flock lock_1;
        lock_1 = lock;
        lock_1.l_type = F_WRLCK;
        fcntl(fd, F_GETLK, &lock_1);
        switch(lock_1.l_type) {
            case F_UNLCK:
                printf("get lock OK\n");
                break;
            case F_RDLCK:
                printf("had got readlock pid = %d\n", lock_1.l_pid);
                break;
            case F_WRLCK:
                printf("had got lock pid = %d\n", lock_1.l_pid);
                break;
        }
        sleep(1);
    }
    printf("set write lock successfully\n");
    getchar();
    close(fd);
    return 0;
}
