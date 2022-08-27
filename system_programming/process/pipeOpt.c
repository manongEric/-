/*************************************************************************
	> File Name: pipeOpt.c
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Apr 2022 11:24:42 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
    int fd[2], n;
    char buf[20];
    if(pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid > 0) {
        close(fd[0]);
        write(fd[1], "hello world\n", 12);
        wait(NULL); // 等待任意一个孩子结束
    } else {
        close(fd[1]);
        n = read(fd[0], buf, 20);
        write(1, buf, n);
    }
    return 0;
}
