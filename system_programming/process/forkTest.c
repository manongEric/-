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
    int t = 10;
    printf("%d", getpid());
    while (t--) {
        pid_t childpid = fork();
        if (childpid < 0) {
            perror("fork");
            exit(1);
        }
        if (childpid == 0) {
            printf("child[%d] self id %d, parent id %d\n", t, getpid(), getppid());
            sleep(1);        
            break;
        }
    }
    sleep(2);
    return 0;
}
