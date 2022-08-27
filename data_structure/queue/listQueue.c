/*************************************************************************
	> File Name: ListQueue_re.c
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Apr 2022 01:46:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
    int val;
    int *next;
}Node;

typedef struct Queue{
    Node *head;
    Node *tail;
    int len;
}Queue;

Node *initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}
void freeNode(Node *n) {
    if (!n)
        return;
    free(n);
    return;
}

Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->len = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void freeQueue(Queue *q) {
    if (!q)
        return;
    Node *p = q->head, *k;
    while (p) {
        k = p;
        p = p->next;
        freeNode(k);
    }
    free(q);
    return;
}

int push(Queue *q, int val) {
    if (!q)
        return 0;
    Node *n = initNode(val);
    if (!q->head) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
    return 1;
}

int isEmpty(Queue *q) {
    return !q || q->head == NULL;
}

int pop(Queue *q) {
    Node *k = q->head;
    int temp = k->val;
    q->head = k->next;
    freeNode(k);

    if (!q->head)
        q->tail = NULL;
    return temp;
} 

void showQueue(Queue *q) {
    if (!q)
        return;
    Node *p = q->head;
    printf("Queue :[");
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL]\n");
    return;
}
int main() {
    srand(time(0));
    Queue *q = initQueue(1);
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
