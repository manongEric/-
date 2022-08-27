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
int q[num];
sem_t blank_number, goods_number;
sem_t mutex;
int head, tail;

void *producer(void *arg) {
    while(1) {
        sem_wait(&blank_number);
        sem_wait(&mutex);
        q[tail] = rand() % 100 + 1;
        printf("produce %d\n", q[tail]);
        tail = (tail + 1) % num;
        sem_post(&mutex);
        sem_post(&goods_number);
        sleep(rand() % 3);
    }
}

void *consumer(void *arg) {
    while (1) {
        sem_wait(&goods_number);
        sem_wait(&mutex);
        printf("consum %d\n", q[head]);
        q[head] = 0;
        head = (head + 1) % num;
        sem_post(&mutex);
        sem_post(&blank_number);
        sleep(rand() % 3);
            
    }
}

int main() {
    srand(time(NULL));
    sem_init(&mutex, 0, 1);
    sem_init(&blank_number, 0, 5);
    sem_init(&goods_number, 0, 0);
    pthread_t pid, cid;
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    
    
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}
