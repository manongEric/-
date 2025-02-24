/*************************************************************************
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Apr 2022 07:56:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
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
    printf("%d,", root->val);
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

typedef struct Stack{
    Node **data;//每个结点的地址，结点本身就是Node*
    int size, top;
}Stack;

Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
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

int push(Stack *s, Node *n) {
    if (!s)
        return 0;

    if (s->top == s->size - 1)
        return 0;

    s->data[++s->top] = n;
    return 1;
}

int isEmpty(Stack *s) {
    return s->top == -1 || !s;
}

Node* pop(Stack *s) {
    return s->data[s->top--];
}

Node *builtTree(char *str) {
    Stack *s = initStack(strlen(str) / 2);
    Node *root, *n;
    int flag = 0;
    int t = 0;
    while (str[0]) {
        switch(str[0]) {
            case '(':
                push(s, n);
                flag = 0;
                break;
            case ',':
                flag = 1;
                break;
            case ')':
                root = pop(s);
                break;
            default :
                if (str[0] < '0' || str[0] > '9') {
                    break;
                }
                t = 0;
                while (str[0] >= '0' && str[0] <= '9') {
                    t = t * 10 + str[0] - '0';  
                    str++;
                }
                n = initNode(t);
                if (!isEmpty(s)) {
                    flag ? (s->data[s->top]->right = n) : (s->data[s->top]->left = n);   
                }
                str--;
        }
        str++;
    }
    freeStack(s);
    return root;
}

int main() {
    Tree *t = initTree(t);
    
    char str[100];
    scanf("%s", str);

    t->root = builtTree(str);
    printf("%p\n", t->root);

    preorderTree(t);
    guangTree(t);
    freeTree(t);
    return 0;
}
