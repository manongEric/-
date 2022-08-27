/*************************************************************************
	> File Name: forkOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Apr 2022 03:24:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
    char *msg;
    int n;
    pid_t childpid = fork();
    if (childpid < 0) {
        perror("fork");
        exit(1);
    }
    if (childpid == 0) {
        msg = "chil process\n";
        n = 6;
    } else {
        msg = "parent process\n";
        n = 3;
    }
    while (n--) {
        printf("%s", msg);
        sleep(1);
    }
    return 0;
}
