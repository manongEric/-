/*************************************************************************
	> File Name: binary_search_tree.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 May 2022 04:19:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef struct Node{
    int val, h;
    struct Node *lchild, *rchild;
}Node;
#define max(a, b) ((a) > (b) ? (a) : (b))
Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->val = -1;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *initNode(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->h = 1;
    n->lchild = n->rchild = NIL;
    return n;
}

void update_height(Node *root) {
    root->h = max(root->lchild->h, root->rchild->h) + 1;
    return;
} 
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}
Node *maintain(Node *root) {
    if (abs(root->lchild->h - root->rchild->h) <= 1) return root;
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->rchild->h > root->lchild->lchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    }else {
        if (root->rchild->lchild->h > root->rchild->rchild->h) {
            root->rchild = right_rotate(root->rchild);//小右
        }
        root = left_rotate(root);//大左
    }
    return root;
}
Node *insertNode(Node *root, int val) {
    if (root == NIL)
        return initNode(val);
    if (root->val == val) return root;
    if (val > root->val)  root->rchild = insertNode(root->rchild, val);
    else root->lchild = insertNode(root->lchild, val);
    update_height(root);
    return maintain(root);//回溯调整
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
        if (root->lchild || root->rchild) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predessor(root);
            root->val = temp->val;
            root->lchild = erase(root->lchild, temp->val);
        }
    }
    update_height(root);
    return maintain(root);
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
void output(Node *root) {
    if (root == NIL) return ;

    printf("(%d(%d) | (%d, %d))\n", root->val, root->h, root->lchild->val, root->rchild->val);
    output(root->lchild);
    output(root->rchild);
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

    output(root);

    freeNode(root);
    return 0;
}
