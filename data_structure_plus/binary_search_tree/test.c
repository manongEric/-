/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Aug 2022 02:49:46 PM CST
 ************************************************************************/

#include<stdio.h>

typedef struct Node{
    int val, size;
    struct Node *lchild, *rchild;
}Node;

Node __NIL;

int main() {
    if (&__NIL) {
        printf("Yes\n");
    }

    return 0;
}
