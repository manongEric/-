/*************************************************************************
	> File Name: threadAdd.c
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Apr 2022 01:13:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
pthread_mutex_t add_lock =  PTHREAD_MUTEX_INITIALIZER;
int cnt = 0;
void *cntAdd(void *arg) {
    int val;
    for (int i = 0; i < 5000; i++) {
        pthread_mutex_lock(&add_lock);
        val = cnt;
        printf("%p : %d\n",(void *)pthread_self(), val);
        cnt = val + 1;
        pthread_mutex_unlock(&add_lock);
    }
    return NULL;
}

int main() {
    pthread_t tida, tidb;

    pthread_create(&tida, NULL, cntAdd, NULL);
    pthread_create(&tidb, NULL, cntAdd, NULL);

    pthread_join(tida, NULL);
    pthread_join(tidb, NULL);

    return 0;
}
