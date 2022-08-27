/*************************************************************************
	> File Name: sigMask.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Apr 2022 10:27:28 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
void print_sig(const sigset_t *set) {
    for (int i = 1; i < 32; i++) {
        sigismember(set, i) ? putchar('1') : putchar('0');
    }
    putchar(10);
    return;
}
int main() {
    sigset_t set, oldset, pset;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    sigprocmask(SIG_BLOCK, &set, &oldset);

    int cnt = 10;
    while (cnt--) {
        sigpending(&pset);
        print_sig(&pset);
        sleep(1);
    }
    sigprocmask(SIG_SETMASK, &oldset, NULL);
    int ans = 10;
    while (ans--) {
        sleep(1);
        printf("pass 1 sec\n");
    }
    return 0;
}
