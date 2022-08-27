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
    p->flag += 1;
}

int find(Node *root, const char *str) {
    Node *p = root;
    int ans = 0;
    for (int i = 0; str[i]; i++) {
        p = p->next[str[i] - 'a'];
        if (p == NULL) return ans;
        ans += p->flag;
    }
    return ans;
}
void output(Node *root, int k, char *buff) {
    if (!root) return;
    buff[k] = 0;
    if (root->flag) {
        printf("%s\n", buff);
    }
    for (int i = 0; i < num; i++) {
        buff[k] = 'a' + i;
        output(root->next[i], k + 1, buff);
    }
}
void clear(Node *root) {
    if (!root) return;
    for (int i = 0; i < num; i++) {
        clear(root->next[i]);
    }
    free(root);
}

char str[1000005];
int main() {
    int n, m;
    Node *root = initNode();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", str);

        printf("%d\n", find(root, str));
    }
    clear(root);
    return 0;
}
