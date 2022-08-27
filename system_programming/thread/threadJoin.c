/*************************************************************************
	> File Name: threadJoin.c
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Apr 2022 12:51:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

void *thr_fn1(void *arg) {
    printf("thread 1 returning\n");
    return (void *)1;
}

void *thr_fn2(void *arg) {
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
    return NULL;
}
void *thr_fn3(void *arg) {
    while (1) {
        printf("thread 3 sleeping\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tid;
    void *sts;

    pthread_create(&tid, NULL, thr_fn1, NULL);
    pthread_join(tid, &sts);
    printf("thread 1 exit with code %ld\n", (long)sts);

    pthread_create(&tid, NULL, thr_fn2, NULL);
    pthread_join(tid, &sts);
    printf("thread 2 exit with code %ld\n",(long)sts);

    pthread_create(&tid, NULL, thr_fn3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &sts);
    printf("thread 3 exit with code %ld\n", (long)sts);

    return 0;
}
