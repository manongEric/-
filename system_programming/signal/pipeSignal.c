/*************************************************************************
	> File Name: killOpt.c
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Apr 2022 01:49:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int fd[2];

    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid) {
        close(fd[0]);
        close(fd[1]);
        int sts;
        wait(&sts);
        if (WIFSIGNALED(sts)) {
            printf("child terminate by signal %d\n", WTERMSIG(sts));
        } else {
            printf("child exit other way\n");
        }
    } else {
        sleep(3);    
        close(fd[0]);
        write(fd[1], "hello\n", 6);
    }
    
    return 0;
}
