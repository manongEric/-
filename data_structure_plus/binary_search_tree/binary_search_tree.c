/*************************************************************************
	> File Name: binary_search_tree.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 May 2022 04:19:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    int val, size;
    struct Node *lchild, *rchild;
}Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->val = 0;
    NIL->size = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *initNode(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->size = 1;
    n->lchild = n->rchild = NIL;
    return n;
}

void update_size(Node *root) {
    root->size = root->lchild->size + root->rchild->size + 1;
    return;
} 
Node *insertNode(Node *root, int val) {
    if (root == NIL)
        return initNode(val);
    if (root->val == val) return root;
    if (val > root->val)  root->rchild = insertNode(root->rchild, val);
    else root->lchild = insertNode(root->lchild, val);
    update_size(root);
    return root;
}

Node *predessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}
Node *erase(Node *root, int val) {
    if (root == NIL) return root;
    if (val > root->val) 
        root->rchild = erase(root->rchild, val);
    else if (val < root->val) 
        root->lchild = erase(root->lchild, val);
    else { 
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        } else {
            Node *temp = predessor(root);
            root->val = temp->val;
            root->lchild = erase(root->lchild, temp->val);
        }
    }
    update_size(root);
    return root;
}

void freeNode(Node *n) {
    if (n == NIL)
        return;
    freeNode(n->lchild);
    freeNode(n->rchild);
    free(n);
    return;
}

void preorder(Node *root) {
    if (root == NIL)
        return;

    printf("%d ", root->val);
    preorder(root->lchild);
    preorder(root->rchild);
    return;
}
void inorder(Node *root) {
    if (root == NIL)
        return;

    inorder(root->lchild);
    printf("%d ", root->val);
    inorder(root->rchild);
    return;
}
void postorder(Node *root) {
    if (root == NIL)
        return;

    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->val);
    return;
}

int find_k(Node *root, int k) {
    if (root->rchild->size >= k) return find_k(root->rchild, k);
    if (root->rchild->size + 1 == k) return root->val;
    return find_k(root->lchild, k - root->rchild->size - 1);
}
int main() {
    int a, k;
    srand(time(0));
    Node *root = NIL;
    scanf("%d", &a);
    for (int i = 0; i  < a; i++) {
        root = insertNode(root, rand() % 100);
    }
    preorder(root);printf("\n");
    inorder(root);printf("\n");
    postorder(root);printf("\n");
    
    while (~scanf("%d", &k)) {
        printf("find %d element is %d\n",k, find_k(root, k));
    }
    freeNode(root);
    return 0;
}
