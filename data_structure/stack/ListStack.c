/*************************************************************************
	> File Name: ListStack.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Apr 2022 08:16:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *head;//部署虚拟头结点
    int len;
}Stack;

Node *initNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n)
        return NULL;
    n->next = NULL;
    n->val = val;
    return n;
}

void freeNode(Node *n) {
    if (n) {
        free(n);
    }
    return;
}

Stack *initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->head = NULL;
    s->len = 0;
    return s;
}

void freeStack(Stack *s) {
    if (!s) 
        return;
    Node *p = s->head, *k;
    while (p) {
        k = p;
        p = p->next;
        freeNode(k);
    }
    free(s);
    return;
}

int push(Stack *s, int val) {//头插
    if (!s)
        return 0;
    Node *n = initNode(val);
    if (!n) 
        return 0;
    n->next = s->head;
    s->head = n;
    s->len++;
    return 1;
}

int isEmpty(Stack *s) {
    return !s || !s->head;
}

int pop(Stack *s) {
    if (!s) {
        return 0;
    }
    Node *k = s->head;
    int temp = k->val;
    s->head = s->head->next;
    freeNode(k);
    s->len--;
    return temp;
}
void showStack(Stack *s) {
    if (!s)
        return;
    Node *p = s->head;
    printf("Stack :[");
/*    for (int i = 1; i <= s->len; i++) {
        printf("%d->", p->val);
        p = p->next;
    }*/
    while(p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL]\n");
}

int main() {
    srand(time(0));
    Stack *s = initStack();
    int cnt = 20;
    while (cnt--) {
        int opt = rand() % 4;
        int val = rand() % 100;
        switch(opt) {
            case 0:
            case 1:
            case 2:
                printf("push %d, res is %d\n", val, push(s, val));
                break;
            case 3:
                isEmpty(s) ? printf("pop faily\n") : printf("pop %d\n", pop(s));
                break;
        }
        showStack(s);
    }
    freeStack(s);
    return 0;
}
