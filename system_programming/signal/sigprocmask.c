/*************************************************************************
	> File Name: sigprocmask.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Apr 2022 12:11:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>

void func(int signo) {
    printf("get signo = %d  has changed\n", signo);
    return;
}
int main() {
    struct sigaction newact, oldact;
    newact.sa_handler = func;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGINT, &newact, &oldact);
    int n = 10;
    while (n--) {
        sleep(1);
    }
    sigaction(SIGINT, &oldact, NULL);
    return 0;
}
