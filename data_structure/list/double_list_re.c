/*************************************************************************
	> File Name: list_re.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Apr 2022 11:59:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct List{
    Node head;
    int len;
}List;

Node *init(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void freeNode(Node *n) {
    if (!n) 
        return;
    free(n);
    return;
} 

List *initList() {
    List *l = (List *)malloc(sizeof(List));
    l->len = 0;
    l->head.next = NULL;
    return l;
}

void freeList(List *l) {
    Node *p, *k;
    p = l->head.next;

    while (p) {
        k = p;
        p = p->next;
        freeNode(k);
    }

    free(l);
    return;
}

int insertNode(List *l, int idx, Node *n) {
    if (!l) {
        return 0;
    }
    if (idx < 0 || idx > l->len) {
        return 0;
    }
    Node *p = &(l->head);
    while (idx--) {
        p = p->next;
    }

    n->next = p->next;
    p->next = n;

    n->prev = p;
    if (n->next) {
        n->next->prev = n;
    }
    l->len++;
    return 1;
}
int insertList(List *l, int idx, int val) {
    Node *n = init(val);
    if (!insertNode(l, idx, n)) {
        freeNode(n);
        return 0;
    }
    return 1;
}

int erase(List *l, int idx) {
    if (!l) {
        return 0;
    }

    if (idx < 0 || idx >= l->len) {
        return 0;
    }

    Node *p = &(l->head), *k;
    while (idx--) {
        p = p->next;
    }
    k = p->next;
    p->next = p->next->next;

    if (k->next) {
        k->next->prev = p;
    } 
    freeNode(k);
    return 1;
}

int reverseList(List *l) {
    Node *p = l->head.next, *k;

    l->len = 0;
    l->head.next = NULL;

    while (p) {
        k = p;
        p = p->next;
        insertNode(l, 0, k);
    }

    return 1;
}

void showList(List *l) {
    if (!l) {
        return ;
    }
    printf("List: +[");
    Node *p = l->head.next;
    Node *k = &(l->head);
    while(p) {
        k = p;
        printf("%d->", p->val);
        p = p->next;
    } 
    printf("NULL]\n");

    printf("List :-[");
    while (k != &(l->head)) {
        printf("%d->", k->val);
        k = k->prev;
    }
    printf("HEAD]\n");
}

int main() {
    srand(time(0));
    List *l = initList();
    int cnt = 20;
    while (cnt--) {
        int opt = rand() % 5;
        int val = rand() % 100;
        int idx = rand() % (l->len + 3) - 1;
        switch(opt) {
            case 0:
            case 1:
            case 2:
                printf("insert %d at %d idx, res = %d\n", val, idx, insertList(l, idx, val));
                break;
            case 3:
                printf("erase %d idx, res = %d\n", idx, erase(l, idx));
                break;
            case 4:
                printf("reverse the list, res = %d\n", reverseList(l));
                break;
        }
        showList(l);
    }
    freeList(l);
    return 0;
}
