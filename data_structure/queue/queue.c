/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Apr 2022 10:06:51 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Queue{
    int *data;
    int size, head, tail;
}Queue;

Queue* initQueue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->size = n;
    q->head = q->tail = 0;
    return q;
}

void freeQueue(Queue *q) {
    if (!q)
        return;
    free(q->data);
    free(q);
    return;
}
int expand(Queue *q) {
    if (!q)
        return 0;
    int expsize = q->size;
    int *temp;
    while (expsize) {
        temp = (int *)malloc(sizeof(int) * (expsize + q->size));
        if (temp) 
            break;
        expsize >>= 1;
    }
    if (!temp)
        return 0;
    int j, i;
    for (i = q->head, j = 0; i != q->tail; i = (i + 1) % q->size, j++) {
        temp[j] = q->data[i];
    }
    free(q->data);
    q->data = temp;
    q->tail = j;
    q->head = 0;
    q->size += expsize;
    printf("expand successfully, new size is %d\n", q->size);
    return 1;

}
int push(Queue *q, int val) {
    if (!q) 
        return 0;
    if ((q->tail + 1) % q->size == q->head) 
        if (!expand(q))
            return 0;

    q->data[q->tail] = val;
    q->tail = (q->tail + 1) % q->size;
    return 1;
}

int isEmpty(Queue *q) {
    return !q || q->tail == q->head;
}

int pop(Queue *q) {
    int temp = q->data[q->head];
    q->head = (q->head + 1) % q->size;
    return temp;
}

void showQueue(Queue *q) {
    if (!q)
        return;

    printf("Queue :[");
    for (int i = q->head; i != q->tail; i = (i + 1) % q->size) {
        if (i != q->head) printf(", ");
        printf("%d", q->data[i]);
    }
    printf("]\n");
    return;
}

int main() {
    Queue *q = initQueue(1);
    srand(time(0));
    int cnt = 20;
    while (cnt--) {
        int opt = rand() % 4;
        int val = rand() % 100;
        switch(opt) {
            case 0:
            case 1:
            case 2:
                printf("push %d, res is %d\n", val, push(q, val));
                break;
            case 3:
                isEmpty(q) ? printf("pop nothing\n") : printf("pop %d\n", pop(q));
                break;
        }
        showQueue(q);
    }

    freeQueue(q);
    return 0;
}
