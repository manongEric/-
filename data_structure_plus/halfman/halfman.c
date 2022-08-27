/*************************************************************************
	> File Name: halfman.c
	> Author: 
	> Mail: 
	> Created Time: Sat 28 May 2022 07:53:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define swap(a, b) {\
    __typeof(a) __c = a;\
    a = b, b = __c;\
}
typedef struct Node {
    char c;
    double freq;
    struct Node *left, *right;
}Node;

typedef struct Heap {
    Node **data;
    int size, len;
}Heap;
Node *initNode(char c, double freq, Node *left, Node *right) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->freq = freq;
    n->c = c;
    n->left = left;
    n->right = right;
    return n;
}

void clearNode(Node *root) {
    if (!root) return;
    clearNode(root->left);
    clearNode(root->right);
    free(root);
    return;
}

Heap *initHeap(int n) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (Node **)malloc(sizeof(Node) * n + 5);
    h->size = n;
    h->len = 0;
    return h;
}
Node *top(Heap *h) {
    return h->data[1];
}
int size(Heap *h) {
    return h->len;
}
int empty(Heap *h) {
    return !h || h->len == 0;
}

int less(Node *n1, Node *n2) {
    return n1->freq < n2->freq;
}
void up_maintain(Heap *h, int ind) {
    if (ind == 1) return;
    if (less(h->data[ind], h->data[ind >> 1])) {
        swap(h->data[ind], h->data[ind >> 1]);
        up_maintain(h, ind >> 1);
    }
    return;
}
void push(Heap *h, Node *n) {
    if (h->len == h->size) 
        return;

    h->data[++h->len] = n;
    up_maintain(h, h->len);
    return;
}
void down_maintain(Node **data, int ind, int len) {
    while ((ind << 1) <= len) {
        int temp = ind, l = ind << 1, r =ind << 1 | 1;
        if (less(data[l], data[temp])) {
            temp = l;
        }

        if (r <= len && less(data[r], data[temp])) {
            temp = r;
        }
        if (temp == ind) 
            break;

        swap(data[ind], data[temp]);
        ind = temp;
    }
    return;
}
void pop(Heap *h) {
    if (empty(h)) return;

    h->data[1] = h->data[h->len];
    h->len -= 1;

    down_maintain(h->data, 1, h->len);
}
void clearHeap(Heap *h) {
    if (!h) return;
    free(h->data);
    free(h);
    return;
}
Node *buikdHalfman (Heap *h) {
    while (size(h) > 1) {
        Node *a = top(h); pop(h);
        Node *b = top(h); pop(h);
        push(h, initNode(0, a->freq + b->freq, a, b));
    }
    return top(h);
}

void gethalfmanCode(Node *root, int k, char *buff, char **code) {
    if (!root) return;
    buff[k] = 0;//每一层都要以0为终止符
    if (root->c) {
        code[root->c] = strdup(buff);
        return;
    }
    buff[k] = '0';
    gethalfmanCode(root->left, k + 1, buff, code);
    buff[k] = '1';
    gethalfmanCode(root->right, k + 1, buff, code);
    return;
}
int main() {
    int n;
    scanf("%d", &n);
    Heap *h = initHeap(n);
    for (int i = 0; i < n; i++) {
        char ch[10];//字符设置为字符数组，准确读取可见字符（除了26个字母以外的字符）
        double freq;
        scanf("%s%lf", ch, &freq);
        push(h, initNode(ch[0], freq, NULL, NULL));
    }
    Node *root = buikdHalfman(h);
    char *code[256] = {0}, buff[100];
    gethalfmanCode(root, 0, buff, code);
    for (int i = 1; i < 256; i++) {
        if (code[i] == NULL) continue;
        printf("%c %s\n", i, code[i]);
    }
    clearHeap(h);
    return 0;
}
