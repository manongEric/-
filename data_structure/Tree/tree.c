/*************************************************************************
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Apr 2022 07:56:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Tree {
    Node *root;
    int len;
}Tree;

Node *initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}

void freeNode(Node *p) {
    if (!p)
        return;
    free(p);
    return;
}

Tree *initTree() {
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    t->len = 0;
    return t;
}

void freeAll(Node *root) {
    if (!root)
        return;
    freeAll(root->left);
    freeAll(root->right);
    freeNode(root);
    return;
}

void freeTree(Tree *t) {
    if (!t)
        return;
    freeAll(t->root);
    free(t);
    return;
}

Node *insertNode(Node *root, int val) {
    if (!root) {
        Node *n = initNode(val);
        return n;
    }
    if (val > root->val) {
        root->right = insertNode(root->right, val);
    } else {
        root->left = insertNode(root->left, val);
    }

    return root;
}

void insertTree(Tree *t, int val) {
    if (!t)
    return;
    t->root = insertNode(t->root, val);
    t->len++;
}
void preorderTrav(Node *root) {
    if (!root) 
        return;
    printf("%d, ", root->val);
    preorderTrav(root->left);
    preorderTrav(root->right);
    return;
}
void preorderTree(Tree *t) {
    if (!t)
        return;
    printf("pre:[");
    preorderTrav(t->root);
    printf("]\n");
}

void guang(Node *root) {
    if (!root) {
        return;
    }
    printf("%d", root->val);
    if (!root->left && !root->right) {
        return;
    }
    printf("(");
    guang(root->left);
    printf(",");
    guang(root->right);
    printf(")");
    return; 
}
void guangTree(Tree *t) {
    if (!t)
        return;
    printf("guang :[");
    guang(t->root);
    printf("]\n");
    return;
}
void inorderTrav(Node *root) {
    if (!root) 
        return;
    inorderTrav(root->left);
    printf("%d, ", root->val);
    inorderTrav(root->right);
    return;
}

void inorderTree(Tree *t) {
    if (!t)
        return;
    printf("ino:[");
    inorderTrav(t->root);
    printf("]\n");
}
void postorderTrav(Node *root) {
    if (!root) 
        return;
    postorderTrav(root->left);
    postorderTrav(root->right);
    printf("%d, ", root->val);
    return;
}
void postorderTree(Tree *t) {
    if (!t)
        return;
    printf("pos:[");
    postorderTrav(t->root);
    printf("]\n");
}
Node *findNode(Node *root, int val) {
    if (!root) {
        return NULL;
    }

    if (root->val == val) {
        return root;
    }

    if (root->val > val) 
        return findNode(root->left, val);
    else 
        return findNode(root->right, val);
    
}
Node *findTree(Tree *t, int val) {
    if (!t) {
        return NULL;
    }
    return findNode(t->root, val);
}

int main() {
    srand(time(0));
    Tree *t = initTree();


    int cnt = 10;
    int want;
    while (cnt--) {
        int val = rand() % 100;
        insertTree(t, val);
        if (cnt == 5) {
            want = val;
        }
    }
    preorderTree(t);
    inorderTree(t);
    postorderTree(t);

    Node *find = findTree(t, want);
    //#x 16进制  前加前缀0x
    find ? printf("find %d at %p, val = %d\n", want, find, find->val) : printf("not fount\n");
    guangTree(t);
    freeTree(t);
    return 0;
}
