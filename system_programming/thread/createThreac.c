/*************************************************************************
	> File Name: createThreac.c
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Apr 2022 11:13:51 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
pthread_t ntid;
void printid(char *); 
void *thr_fn(void *arg) {
    printid(arg);
    printf("%s tid %p\n", (char *)arg, (void *)ntid);
    return NULL;
}

void printid(char *tip) {
    pid_t pid = getpid();
    pthread_t tid = pthread_self();

    printf("%s pid : %u tid: %u (%p)\n", tip, pid, (int)tid, (void *)tid);
}
int main() {
    int ret;
    ret = pthread_create(&ntid, NULL, thr_fn, "new thread");
    if (ret) {
        printf("create thread err : %s\n", strerror(ret));
        exit(1);
    }
    sleep(1);
    printid("main thread");
    return 0;
}
