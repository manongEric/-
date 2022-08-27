/*************************************************************************
	> File Name: Dictree.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 May 2022 02:17:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define num 26

typedef struct node{
    int flag;
    struct node *next[num];
}Node;

Node *initNode() {
    Node *n = (Node *)malloc(sizeof(Node));
    n->flag = 0;
    memset(n->next, 0, sizeof(Node *) * num);
    return n;
}

void insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (p->next[ind] == NULL) p->next[ind] = initNode();
        p = p->next[ind];
    }
    p->flag = 1;
}

int find(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        p = p->next[str[i] - 'a'];
        if (p == NULL) return 0;
    }
    return p->flag;
}
void output(Node *root, int k, char *buff) {
    if (!root) return;
    buff[k] = 0;
    if (root->flag) {
        printf("%s\n", buff);
    }
    for (int i = 0; i < num; i++) {
        buff[k] = 'a' + i;
        k++;
        output(root->next[i], k, buff);
        k--; 
    }
    return;
}
void clear(Node *root) {
    if (!root) return;
    for (int i = 0; i < num; i++) {
        clear(root->next[i]);
    }
    free(root);
}

int main() {
    int op;
    char str[100];
    Node *root = initNode();
    while (~scanf("%d", &op)) {
        switch(op) {
            case 1 : 
                scanf("%s", str);
                printf("insert %s to Dietree\n", str);
                insert(root, str);
                break;
            case 2 :
                scanf("%s", str);
                printf("find %s from Dictree = %d\n", str, find(root, str));
                break;
            case 3 :
                output(root, 0, str);
                break;
        }
    }
    clear(root);
    return 0;
}
