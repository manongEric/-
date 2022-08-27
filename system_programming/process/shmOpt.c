/*************************************************************************
	> File Name: shmOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Apr 2022 11:20:18 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#include<sys/wait.h>

int main() {
    key_t key = ftok("./readFIFO.c", 99);
    if (key < 0) {
        perror("ftok");
        exit(1);
    }

    printf("key = %#x\n", key);

    int shmid = shmget(key, 20, IPC_CREAT| 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    printf("shmid = %d\n", shmid);
    char *shmp = shmat(shmid, NULL, 0);
    if (shmp < 0) {
        perror("shmat");
        exit(1);
    }
    printf("shmp = %p\n",shmp);
 //   snprintf(shmp, 20, "hello,world\n");
   // printf("%s", shmp);

    bzero(shmp, 20);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid) {
        while (1) {
            scanf("%s", shmp);
            if (!strcmp(shmp, "quit"))
                break;
        }
        wait(NULL);
    } else {
        while(1) {
            if (!strcmp(shmp, "quit")) {
                break;
            } if (*shmp) {
                printf("child read %s\n", shmp);
                bzero(shmp, 20);
            }
            sleep(1);
        }
    }
    shmdt(shmp);
    return 0;
}
