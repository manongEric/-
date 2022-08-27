/*************************************************************************
	> File Name: threadTree_re.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Apr 2022 06:47:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CHILD 0
#define THREAD 1

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int val;
    int ltag, rtag;
}Node;

Node *initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    n->ltag = CHILD;
    n->rtag = CHILD;
    return n;
}

void freeNode(Node *n) {
    if (!n)
        return;
    free(n);
    return;
}

void freeAll(Node *n) {
    if (!n)
        return;
    if (n->ltag == CHILD) 
        freeAll(n->left);
    if (n->right == CHILD)
        freeAll(n->right);
    freeNode(n);
    return;
}

void insertNode(Node **addr, int val) {
    if (!(*addr)){
        *addr = initNode(val);
        return;
    }
    if (val > (*addr)->val) {
        insertNode(&((*addr)->right), val);
    } else {
        insertNode(&((*addr)->left), val);
    }
    return;
}

void inorderPre(Node *n) {
    if (!n)
        return;
    if (n->ltag == CHILD)
        inorderPre(n->left);
    printf("%d ", n->val);
    if (n->rtag == CHILD) 
        inorderPre(n->right);
    return;
}

Node *pre = NULL;
void builtTree(Node *root) {
    if (!root)
        return;

    builtTree(root->left);
    if (!root->left) {
        root->left = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->right) {
        pre->right = root;
        pre->rtag = THREAD;
    }
    pre = root;
    builtTree(root->right);
    return;
}

Node *getleftMost(Node *p) {
    while (p && p->ltag == CHILD) 
        p = p->left;
    return p;
}

void output(Node *root) {
    if (!root)
        return;

    Node *p = getleftMost(root);
    while(p) {
        printf("%d ", p->val);
        if (p->rtag == CHILD) {
            p = getleftMost(p->right);
        } else {
            p = p->right;
        }
    }
    putchar(10);
    return;
}
int main() {
    srand(time(0));
    int cnt = 10;
    Node *root = NULL;
    while (cnt--) {
        int val = rand() % 100;
        insertNode(&root, val);
        printf("%d ", val);
    }
    putchar(10);

    builtTree(root);
    output(root);
    
    inorderPre(root);
   
    putchar(10);
    freeAll(root);
    return 0;
}
