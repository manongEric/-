/*************************************************************************
	> File Name: ListStack_re.c
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

typedef struct Stack{
    Node *head;
    int len;
}Stack;

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

Stack *initStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->len = 0;
    s->head = NULL;
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

int push(Stack *s, int val) {
    if (!s)
        return 0;
    Node *n = initNode(val);
    n->next = s->head;
    s->head = n;
    return 1;
}

int isEmpty(Stack *s) {
    return !s || s->head == NULL;
}

int pop(Stack *s) {
    Node *k = s->head;
    int temp = k->val;
    s->head = k->next;
    freeNode(k);
    return temp;
} 

void showStack(Stack *s) {
    if (!s)
        return;
    Node *p = s->head;
    printf("Stack :[");
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL]\n");
    return;
}
int main() {
    srand(time(0));
    Stack *s = initStack(1);
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
                isEmpty(s) ? printf("pop nothing\n") : printf("pop %d\n", pop(s));
                break;
        }
        showStack(s);
    }
    freeStack(s);
    return 0;
}
