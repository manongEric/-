/*************************************************************************
	> File Name: threadSem.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Apr 2022 04:42:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<semaphore.h>
#define num 5
sem_t blank_number, car;
sem_t mutex;

void *putcar(void *arg) {
    int m = *(int *)arg;
    sem_wait(&mutex);
    sem_wait(&blank_number);
    printf("Num.%d car has entered\n", m);
    sem_post(&car);
    sem_post(&mutex);
}

void *outcar(void *arg) {
    int m = *(int *)arg;
    sem_wait(&car);
    sem_wait(&mutex);
    printf("Num.%d car has left\n", m);
    sem_post(&blank_number);
    sem_post(&mutex);
}

int main() {
    srand(time(NULL));
    sem_init(&mutex, 0, 1);
    sem_init(&blank_number, 0, 6);
    sem_init(&car, 0, 0);
    pthread_t pid, oid;
    int ret, car[] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < 6; i++) {
        int n = rand() % 10;
        if (n % 2) {
            pthread_create(&pid, NULL, putcar, &car[(i + 1) % 6]);
        } else {
            pthread_create(&oid, NULL, outcar, &car[(i + 1) % 6]);
        }
        if (ret = pthread_join(pid, NULL)) {
            printf("join pid error %s\n", strerror(ret));
        }
        
        if (ret = pthread_join(oid, NULL)) {
            printf("join oid error %s\n", strerror(ret));
        }
        sleep(1);
    }
    return 0;
}
