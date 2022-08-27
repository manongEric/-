/*************************************************************************
	> File Name: hashTable.c
	> Author: 
	> Mail: 
	> Created Time: Mon 02 May 2022 07:50:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

typedef struct Node {
    char *str;
    struct Node *next;
}Node;

typedef struct Hash {
    Node **data;
    int size;
}Hash;

Node *initNode(char *str) {
    Node *n = malloc(sizeof(Node));
    n->str = strdup(str);
    n->next = NULL;
    return n;
}

void freeNode(Node *n) {
    if (!n)
        return;
    free(n->str);
    free(n);
    return;
}

void freeList(Node *head) {
    if (!head)
        return;

    Node *k;
    while (head) {
        k = head;
        head = head->next;
        freeNode(k);
    }
    return;
}

Hash* initHash(int size) {
    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->size = 2 * size;
    h->data = (Node **)calloc(h->size, sizeof(Node*));
    return h;
}

void freeHash(Hash *h) {
    if (!h)
        return;

    for (int i = 0; i < h->size; i++) 
        freeList(h->data[i]);

    free(h->data);
    free(h);
    return;
}

Node *insertNode(Node *head, Node *p) {
    p->next = head;
    return p;
}

int BKDhash(char *str) {
    int seed = 31, hash = 0;
    while (*str) {
        hash = hash * seed + str[0];
        str++;
    }

    return hash & 0x7fffffff;
}

int insertHash(Hash *h, char *str) {
    if (!h)
        return 0;

    int hash = BKDhash(str);
    int idx = hash % h->size;
    h->data[idx] = insertNode(h->data[idx], initNode(str));
    return 1;
}

Node *searchList(Node *p, char *str) {
    while(p && strcmp(p->str, str)) {
        p = p->next;
    }
    return p;
}

Node *searchHash(Hash *h, char *str) {
    if (!h)
        return NULL;

    int hash = BKDhash(str);
    int idx = hash % h->size;

    return searchList(h->data[idx], str);
}

char *makeStr(char *str, int n) {
    int len = rand() % (n - 1) + 1;
    char temp;
    for (int i = 0; i < len; i++) {
        switch(rand() % 3) {
            case 0:
                temp = 'A' + rand() % 26;
                break;
            case 1:
                temp = 'a' + rand() % 26;
                break;
            case 2:
                temp = '0' + rand() % 10;
                break;
            default:
                temp = 'x';
        }
        str[i] = temp;
    }
    str[len] = 0;
    return str;
}

int main() {
    srand(time(NULL));

    #define N 10
    //地址常量
    char str[8];
    int cnt = N;
    Hash *h = initHash(N);
    

    while (cnt--) {
        makeStr(str, 8);
        insertHash(h, str);
        printf("%s ", str);
    }
    putchar(10);

    while (~scanf("%s", str)) {
        if (!strcmp(str, "q"))
            break;

        Node *f = searchHash(h, str);
        if (f) {
            printf("hash = %d addr = %p str = %s\n", BKDhash(str), f, f->str);
        } else {
            printf("%s not found ~\n", str);
        }
    }
    freeHash(h);
    return 0; 

}
