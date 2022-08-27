/*************************************************************************
	> File Name: 树三元组.c
	> Author: 
	> Mail: 
	> Created Time: Sun 29 May 2022 08:04:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char ch;
    struct Node *left, *right;
}Node;

Node *arr[30];
char str[10];

Node *initNode(char c) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->left = n->right = NULL;
    n->ch = c;
    return n;
}

void freeNode(Node *root) {
    if (!root) return ;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
    return;
}
void output(Node *root) {
    if (!root) return;
    printf("%c", root->ch);
    if (!root->left && !root->right) return;
    printf("(");
    output(root->left);
    printf(",");
    output(root->right);
    printf(")");
    return;
}
int main() {
    Node *root = NULL, *p;
    while (scanf("%s", str)) {
        if (str[0] == '^' && str[1] == '^') {
            break;
        }
        p = initNode(str[1]);
        arr[str[1] - 'A'] = p; //层次顺序，所以要不断覆盖
        if (str[0] == '^') {
            root = p;
            continue;
        }
        switch(str[2]) {
            case 'L': arr[str[0] - 'A']->left = p;break;
            case 'R': arr[str[0] - 'A']->right = p;break;
        }
    }

    output(root);

    return 0;
}
