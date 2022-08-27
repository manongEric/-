/*************************************************************************
	> File Name: msgOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2022 09:43:54 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/msg.h>
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
#define MSGLEN 20
typedef struct msgbuf{
    long mtype;
    char mtext[MSGLEN];
}MSG;

int main() {
    key_t key = ftok("./tube", 9);
    printf("key = %#x\n", key);
    int mqid = msgget(key, IPC_CREAT | 0666);
    printf("mqid = %d\n", mqid);

    MSG msg;
    msg.mtype = 1;
    strncpy(msg.mtext, "hello world\n", MSGLEN);
    msgsnd(mqid, &msg, MSGLEN, 0);
    //消息队列结构体？？
    msg.mtype = 2;
    strncpy(msg.mtext, "I am Online\n", MSGLEN);
    msgsnd(mqid, &msg, MSGLEN, 0);

    return 0;
}
