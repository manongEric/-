/*************************************************************************
	> File Name: mySleep.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Apr 2022 12:37:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>

void func(int signo) {
    return;
}
unsigned int mysleep(unsigned int sec) {
    struct sigaction newact, oldact;
    newact.sa_handler = SIG_IGN;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGALRM, &newact, &oldact);
    alarm(sec);
    pause();

    int unslept;
    unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);
    return unslept;
}

int main() {
    int n = 5;
    while (n--) {
        mysleep(1);
        printf("success\n");
    }
    return 0;
}
