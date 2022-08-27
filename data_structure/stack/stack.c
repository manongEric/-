/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Apr 2022 10:35:34 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct stack{
    int *data;
    int top, size;
}Stack;

int expandStack(Stack *s);
Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}

void freeStack(Stack *s) {
    if (!s) 
        return;
    free(s->data);
    free(s);
    return;
}
//使free后的s指针真正指为空，因此主函数必须传递参数地址，子函数用指针接住地址，修改地址指向
/*void freeStack(Stack **saddr) {
    if (!*saddr) {
        return;
    }
    free((*saddr)->data);
    free((*saddr));
    *saddr = NULL;
    return;
}*/

int push(Stack *s, int val) {
    if (!s) 
        return 0;
    if (s->size - 1 == s->top) {
        if (!expandStack(s)) {
            return 0;
        }
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
    if (!s || isEmpty(s)) 
        return;
    printf("Stack :[");
    for(int i = 0; i <= s->top; i++) {
        if (i != 0) printf(", ");
        printf("%d", s->data[i]);
    }  
    printf("]\n");
    return;
}
int expandStack(Stack *s) {
    if (!s) 
        return 0;
    int expsize = s->size;
    int *temp = s->data;
    while (temp) {
        temp = (int *)realloc(s->data, sizeof(int) * (s->size + expsize));
        if (temp) {
            break;
        }
        expsize >>= 1;
    }
    if (!temp) 
        return 0;
    s->data = temp;
    s->size += expsize;
    printf("expand successfully ~, new size is %d\n", s->size);
    return 1;
}
int main() {
    srand(time(0));
    Stack *s = initStack(5);
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
