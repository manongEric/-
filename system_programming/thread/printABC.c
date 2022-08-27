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

pthread_mutex_t plock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t hasA = PTHREAD_COND_INITIALIZER;
pthread_cond_t hasB = PTHREAD_COND_INITIALIZER;
pthread_cond_t hasBC = PTHREAD_COND_INITIALIZER;
int flag = 2;
void *printA(void *arg) {
    int n = 10;
    char c = *(char *)arg;
    while (n--) {
        pthread_mutex_lock(&plock);
        while (flag != 2) {
            pthread_cond_wait(&hasBC, &plock);
        }
        flag = 0;
        sleep(1);
        printf("%c\n", c);
        pthread_cond_broadcast(&hasA);
        pthread_mutex_unlock(&plock);
    }
}

void *printB(void *arg) {
    int n = 10;
    char c = *(char *)arg;
    while (n--) {
        //sleep不能放前面。要不然条件成立，广播的时候，你还在睡觉
        pthread_mutex_lock(&plock);
        pthread_cond_wait(&hasA, &plock);
        sleep(1);
        printf("%c\n", c);
        flag++;
        pthread_cond_broadcast(&hasB);
        pthread_cond_broadcast(&hasBC);
        pthread_mutex_unlock(&plock);
    }
}

void *printC(void *arg) {
    int n = 10;
    char c = *(char *)arg;
    while (n--) {
        pthread_mutex_lock(&plock);
        pthread_cond_wait(&hasB, &plock);
        sleep(1);
        printf("%c\n", c);
        flag++;
        pthread_cond_broadcast(&hasBC);
        pthread_mutex_unlock(&plock);
    }
}


int main(void) {
    srand(time(NULL));
    char a = 'A', b = 'B', c = 'C';
    pthread_t pid1, pid2, pid3;
    pthread_create(&pid1, NULL, printA, &a);
    pthread_create(&pid2, NULL, printB, &b);
    pthread_create(&pid3, NULL, printC, &c);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid3, NULL);

    return 0;
}
