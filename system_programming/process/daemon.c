/*************************************************************************
	> File Name: daemon.c
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Apr 2022 03:32:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid) {
        exit(0);
    }

    pid_t cid = setsid();
    printf("daemon id is %d\n", cid);
    if (chdir("/") < 0) {
        perror("chdir");
        exit(1);
    }
    close(0);
    open("/dev/null", O_RDWR);
    dup2(0, 1);
    dup2(0, 2);
    while (1) {
        sleep(1);
    }
    return 0;
}
