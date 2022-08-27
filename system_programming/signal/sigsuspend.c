/*************************************************************************
	> File Name: sigsuspend.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Apr 2022 10:43:39 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
void sig_alarm(int signo) {
    return;
}
unsigned int mysleep(unsigned int sec) {
    struct sigaction newact, oldact;
    sigset_t newmask, oldmask, susmask;

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGALRM);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    newact.sa_handler = sig_alarm;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);
    sigaction(SIGALRM, &newact, &oldact);

    alarm(sec);

    susmask = oldmask;
    sigdelset(&susmask, SIGALRM);

    sigsuspend(&susmask);

    int unslept;
    unslept = alarm(0);

    sigaction(SIGALRM, &oldact, NULL);
    sigprocmask(SIG_SETMASK, &oldmask, NULL);

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

