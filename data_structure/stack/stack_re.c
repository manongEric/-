/*************************************************************************
	> File Name: stack_re.c
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Apr 2022 01:21:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Stack{
    int *data;
    int size, top;
}Stack;

Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

void freeStack(Stack *s) {
    if (!s)
        return;
    free(s->data);
    free(s);
    return;
}
int expand(Stack *s) {
    int expsize = s->size;
    int *temp;
    while (expsize) {
        temp = (int *)realloc(s->data, sizeof(int) * (s->size + expsize));
        if (temp) {
            break;
        }
        expsize >>= 1;
    }
    if (!temp)
        return 0;
    s->size += expsize;
    s->data = temp;
    printf("expand successfully, new size is %d\n", s->size);
    return 1;
}
int push(Stack *s, int val) {
    if (!s)
        return 0;
    if (s->size - 1 == s->top) {
        if (!expand(s))
            return 0;
    }
    s->data[++s->top] = val;
    return 1;
}

int isEmpty(Stack *s) {
    return !s || s->top == -1;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

void showStack(Stack *s) {
    if (!s)
        return;
    printf("Stack: [");
    for (int i = 0; i <= s->top; i++) {
        if (i != 0) printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
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
