/*************************************************************************
	> File Name: cond.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Apr 2022 12:27:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

typedef struct Goods{
    int data;
    struct Goods *next;
}Goods;

Goods *head = NULL;
pthread_mutex_t headlock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t hasGoods = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    Goods *ng;
    while (1) {
        ng = (Goods *)malloc(sizeof(Goods));
        ng->data = rand() % 100;

        pthread_mutex_lock(&headlock);
        ng->next = head;
        head = ng;
        pthread_cond_broadcast(&hasGoods);
        pthread_mutex_unlock(&headlock);

        printf("produce %d\n", ng->data);
        sleep(rand() % 3);
    }
}

void * consumer(void *arg) {
    Goods *k;
    while (1) {
        pthread_mutex_lock(&headlock);
        while (!head) {
            pthread_cond_wait(&hasGoods, &headlock);
        }

        k = head;
        head = head->next;
        pthread_mutex_unlock(&headlock);
        printf("consum %d\n", k->data);
        free(k);
        sleep(rand() % 3);
    }
}

int main(void) {
    srand(time(NULL));
    
    pthread_t pid, cid1, cid2, cid3, cid4;;
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid1, NULL, consumer, NULL);
    pthread_create(&cid2, NULL, consumer, NULL);
    pthread_create(&cid3, NULL, consumer, NULL);
    pthread_create(&cid4, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid1, NULL);
    pthread_join(cid2, NULL);
    pthread_join(cid3, NULL);
    pthread_join(cid4, NULL);

    return 0;
}
