/*************************************************************************
	> File Name: killOpt.c
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Apr 2022 01:49:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void ctrl_c(int signo) {
    printf("haha\n");
    pid_t pid = getpid();
    kill(pid + 1, SIGUSR1);
    return;
}

void sig_user(int signo) {
    printf("recieve signo %d\n", signo);
    exit(1);
}
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid) {
        struct sigaction newact, oldact;
        newact.sa_handler = ctrl_c;
        newact.sa_flags = 0;
        sigemptyset(&newact.sa_mask);
        sigaction(SIGINT,&newact, &oldact);
       // sleep(3);
        /*if (kill(pid, SIGUSR1) < 0) {
            perror("kill");
            exit(1);
        }*/
       // sigaction(SIGINT,&oldact, NULL);
        int sts;
        wait(&sts);
        if (WIFSIGNALED(sts)) {
            printf("child terminate by signal %d\n", WTERMSIG(sts));
        } else {
            printf("child exit other way %d\n", WEXITSTATUS(sts));
        }
    } else {
        
      /*  sigset_t set, oldset;
        sigemptyset(&set);
        sigaddset(&set, SIGINT);*/

        struct sigaction newact, oldact;
        newact.sa_handler = sig_user;
        newact.sa_flags = 0;
        sigemptyset(&newact.sa_mask);
        sigaddset(&newact.sa_mask, SIGINT);
        sigprocmask(SIG_BLOCK, &newact.sa_mask, NULL);
        sigaction(SIGUSR1,&newact, &oldact);
        while(1) {
            printf("work\n");
            sleep(1);
        }
    }
    
    return 0;
}
