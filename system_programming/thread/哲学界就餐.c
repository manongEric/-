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
sem_t ffork[num];
sem_t mutex;
//互斥锁 + 信号量
/*void *smart_person(void *ptid) {
    int id = *(int *)ptid;
    while(1) {
        printf("%d philosopher is thinking\n", id);
        sleep(rand() % 5);
        sem_wait(&mutex);
        sem_wait(&ffork[id]);
        sem_wait(&ffork[(id + 1) % num]);
        printf("%d is eating\n", id);
        sem_post(&ffork[id]);
        sem_post(&ffork[(id + 1) % num]);
        sem_post(&mutex);
        printf("%d philosopher is end\n", id);
    }
}*/
//奇数先拿右后左，偶数先拿左后右
void *smart_person(void *ptid) {
    int id = *(int *)ptid;
    while(1) {
        printf("%d philosopher is thinking\n", id);
        sleep(rand() % 5);
        if (id % 2 == 0) {
            sem_wait(&ffork[id]);
            sem_wait(&ffork[(id + 1) % num]);
        } else {
            sem_wait(&ffork[(id + 1) % num]);
            sem_wait(&ffork[id]);
        }
        printf("%d is eating\n", id);
        sem_post(&ffork[id]);
        sem_post(&ffork[(id + 1) % num]);
        printf("%d philosopher is end\n", id);
        putchar(10);
    }
}
int main() {
    sem_init(&mutex, 0, 1);
    int idd[] = {0, 1, 2, 3, 4};
    //pthread_t pid[num];
    pthread_t pid1, pid2, pid3, pid4, pid5;
    for (int i = 0; i < num; i++) {
        sem_init(&ffork[i], 0, 1);
    }
   /* for (int i = 0; i < num; i++) {
        pthread_create(&pid[i], NULL, smart_person, &idd[i]);
    }*/
    pthread_create(&pid1, NULL, smart_person, &idd[0]);
    pthread_create(&pid2, NULL, smart_person, &idd[1]);
    pthread_create(&pid3, NULL, smart_person, &idd[2]);
    pthread_create(&pid4, NULL, smart_person, &idd[3]);
    pthread_create(&pid5, NULL, smart_person, &idd[4]);
    /*for (int i = 0; i < num; i++) {
        pthread_join(pid[i], NULL);
    }*/
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid3, NULL);
    pthread_join(pid4, NULL);
    pthread_join(pid5, NULL);
    
    return 0;
}
