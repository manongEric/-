/*************************************************************************
	> File Name: waitOpt.c
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Apr 2022 10:55:18 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        int n = 5;
        while (n--) {
            printf("this is a child process\n");
            sleep(1);
        }
        exit(3);
    } else {
        int stat_val;
        waitpid(pid, &stat_val, 0);
        if (WIFEXITED(stat_val)) {
            printf("child process exited with code %d\n", WEXITSTATUS(stat_val));
        } else if (WIFSIGNALED(stat_val)){
            printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
        }
    }
    return 0;
}
