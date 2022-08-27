/*************************************************************************
	> File Name: threadTree.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2022 08:44:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CHILD 0
#define THREAD 1

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    int ltag, rtag;
}Node;

Node *initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    n->ltag = CHILD;
    n->rtag = CHILD;
    return n;
}

void freeNode(Node *p) {
    if (!p)
        return;
    free(p);
    return;
}

void freeAllNode(Node *root) {
    if (!root)
        return;
    if (root->ltag == CHILD)
        freeAllNode(root->left);
    if (root->rtag == CHILD) 
        freeAllNode(root->right);
    freeNode(root);
    return;
}

void insertNode(Node **raddr, int val) {
    if (!(*raddr)) {
        *raddr = initNode(val);
        return;
    }
    if (val > (*raddr)->val) {
        insertNode(&((*raddr)->right), val);
    } else {
        insertNode(&((*raddr)->left), val);
    }
    return;
}

void inorderTrav(Node *root) {
    if (!root) 
        return;
    if (root->ltag == CHILD)
        inorderTrav(root->left);
    printf("%d ", root->val);
    if (root->rtag == CHILD)
        inorderTrav(root->right);
    return;
}

Node *pre = NULL;
void buildThread(Node *root) {
    if (!root)
        return;

    buildThread(root->left);
    if(!root->left) {
        root->left = pre;
        root->ltag = THREAD;
    }

    if (pre && !pre->right) {
        pre->right = root;
        pre->rtag = THREAD;
    }
    pre = root;
    buildThread(root->right);
    return;
}

Node *getleftMost(Node *p) {
    while (p && p->ltag == CHILD) {
        p = p->left;
    }
    return p;
}

void output(Node *root) {
    if (!root)
        return;

    Node *p = getleftMost(root);
    while(p) {
        printf("%d ", p->val);
        if (p->rtag == CHILD) {
            p =  getleftMost(p->right);
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

    buildThread(root);
    output(root);
    
    inorderTrav(root);
   
    putchar(10);
    freeAllNode(root);
    return 0;
}
