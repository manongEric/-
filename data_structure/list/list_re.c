/*************************************************************************
	> File Name: list_re.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Aug 2022 03:40:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct List{
    Node head;
    int len;
}List;

Node* initNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}
void freeNode(Node* n) {
    if (!n) return;
    free(n);
}

List* initList() {
    List* l = (List*)malloc(sizeof(List));
    l->head.next = NULL;
    l->len = 0;
    return l;
}


