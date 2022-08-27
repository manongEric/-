/*************************************************************************
	> File Name: sigchild.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Apr 2022 11:15:52 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<wait.h>
void sig_child(int signo) {
    int sts;
    pid_t pid = wait(&sts);
    if (WIFEXITED(sts)) {
        printf("proc : %d exit with code %d\n", pid, WEXITSTATUS(sts));
    } else {
        printf("lemon\n");
    }
    return;
}
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid) {
        printf("child 1 is %d\n", pid);

        pid = fork();
        if (pid < 0) {
            perror("fork2");
            exit(1);
        }
        if (pid) {
            printf("child 2 is %d\n", pid);
            struct sigaction newact, oldact;
            newact.sa_handler = sig_child;
            newact.sa_flags = 0;
            sigemptyset(&newact.sa_mask);
            sigaction(SIGCHLD, &newact, &oldact);

            int n = 10;
            while (n--) {
                printf("working\n");
                sleep(1);
            }
        } else {
            sleep(5);
            exit(5);
        }
    } else {
        sleep(3);
        exit(3);
    }
    return 0;
}
