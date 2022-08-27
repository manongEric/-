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
void ctrl_c(int signo) {
    pid_t pid = getpid();
    kill(pid + 1, SIGUSR1);
    kill(pid + 2, SIGUSR2);
    return;
}

void sig_user(int signo) {
    switch(signo) {
        case SIGUSR1 : 
            printf("child1 is killed by parent SIGUSR1!\n");
            exit(1);
            break;
        case SIGUSR2 : 
            printf("child2 is killed by parent SIGUSR2!\n");
            exit(2);
            break;
        default :
            printf("child is killed by parent signo %d!\n", signo);
            exit(3);
            break;
    }
}
/*void sig_user1(int signo) {
    printf("child1 is killed by parent!\n");
    exit(1);
}
void sig_user2(int signo) {
    printf("child2 is killed by parent!\n");
    exit(2);
}*/
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
            newact.sa_handler = ctrl_c;
            newact.sa_flags = 0;
            sigemptyset(&newact.sa_mask);
            sigaction(SIGINT,&newact, &oldact);
            
            int n = 6;
            while (n--) {
                printf("work\n");
                sleep(1);
            }
            if (wait(NULL) == -1) {
                perror("wait");
                exit(1);
            }
        } else {
            raise(SIGUSR1);
            sigset_t set, oldset;
            sigemptyset(&set);
            sigaddset(&set, SIGINT);
            sigprocmask(SIG_BLOCK, &set, &oldset);
            struct sigaction newact1, oldact;
            newact1.sa_handler = sig_user;
            newact1.sa_flags = 0;
            sigemptyset(&newact1.sa_mask);
            sigaction(SIGUSR1,&newact1, &oldact);
            while (1) {
                sleep(1);
            }
        }
        raise(SIGUSR2);
        sigset_t set, oldset;
        sigemptyset(&set);
        sigaddset(&set, SIGINT);
        sigprocmask(SIG_BLOCK, &set, &oldset);
        struct sigaction newact2, oldact;
        newact2.sa_handler = sig_user;
        newact2.sa_flags = 0;
        sigemptyset(&newact2.sa_mask);
        sigaction(SIGUSR2, &newact2, &oldact);
        while (1) {
            sleep(1);
        }
    }
    return 0;
}
