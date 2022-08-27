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
    const char *str;
    struct node *next[num], *fail;
}Node;

typedef struct queue{
    Node **data;
    int head, tail;
}Queue;

int node_cnt = 0;
Node *initNode() {
    node_cnt++;
    Node *n = (Node *)malloc(sizeof(Node));
    n->str = NULL;
    n->fail = NULL;
    memset(n->next, 0, sizeof(Node *) * num);
    return n;
}
Queue *initQueue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->head = q->tail = 0;
    return q;
}

Node *front(Queue *q) {
    return q->data[q->head];
}
int isEmpty(Queue *q) {
    return !q || q->tail == q->head;
}
void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
}

void pop(Queue *q) {
    if (isEmpty(q)) return;
    q->head += 1;
    return;
}

void freeQueue(Queue *q) {
    if (!q) return;
    free(q->data);
    free(q);
}

const char *copy_str(const char *s) {
    int n = strlen(s);
    char *buff = (char *)malloc(sizeof(n + 1));
    strcpy(buff, s);
    return buff;
} 

int ind(char c) {
    return c - 'a';
}
void insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[ind(str[i])] == NULL) p->next[ind(str[i])] = initNode();
        p = p->next[ind(str[i])];
    }
    p->str = copy_str(str);
}

void clear(Node *root) {
    if (!root) return;
    for (int i = 0; i < num; i++) {
        clear(root->next[i]);
    }
    if (root->str) free((char *)root->str);
//    free(root);
}
void initBuildFailQueue(Node *root, Queue *q) {
    for (int i = 0; i < num; i++) {
        if (root->next[i] == NULL)  {
            root->next[i] = root;
            continue;
        }
        root->next[i]->fail = root;
        push(q, root->next[i]);
    }
    return;
}
void built_fail(Node *root) {
    Queue *q = initQueue(node_cnt);
    initBuildFailQueue(root, q);
    while (!isEmpty(q)) {
        Node *p = front(q);//除第一层以后的节点
        for (int i = 0; i < num; i++) {
            if (p->next[i] == NULL) {
                p->next[i] = p->fail->next[i];//路径压缩
                continue;
            }
            Node *k = p->fail->next[i];//找到前驱fail指针下面的所需等价节点
           // while (k != root && k->next[i] == NULL) k = k->fail;
            //if (k->next[i] != NULL) k = k->next[i];
            p->next[i]->fail = k;
            push(q, p->next[i]);
        }
        pop(q);
    }
    freeQueue(q);
    return;
}

void match_ac(Node *root, const char *s) {
    Node *p = root, *q;
    for (int i = 0; s[i]; i++) {
        //while (p != root && p->next[ind(s[i])] == NULL) p = p->fail;
        //if (p->next[ind(s[i])] != NULL) p = p->next[ind(s[i])];
        p = p->next[ind(s[i])]; //路径压缩
        printf("input %c : %p\n", s[i], p);
        q = p;
        while (q) {
            if (q->str != NULL) printf("find %s\n", q->str);
            q = q->fail;
        }
    }
    return ;
}
int main() {
    int n;
    char str[100];
    Node *root = initNode();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }

    built_fail(root);
    scanf("%s", str);
    match_ac(root, str);
    clear(root);
    return 0;
}
