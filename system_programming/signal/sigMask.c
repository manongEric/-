/*************************************************************************
	> File Name: sigMask.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Apr 2022 10:27:28 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main() {
    sigset_t set, oldset;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    sigprocmask(SIG_BLOCK, &set, &oldset);

    int cnt = 6;
    while (cnt--) {
        sleep(1);
        printf("pass 1 sec\n");
    }
    sigprocmask(SIG_SETMASK, &oldset, NULL);
    int ans = 10;
    while (ans--) {
        sleep(1);
        printf("pass 1 sec\n");
    }
    return 0;
}
