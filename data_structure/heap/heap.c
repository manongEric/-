/*************************************************************************
	> File Name: heap.c
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Apr 2022 04:10:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
typedef struct Heap{
    int *data;
    int size, len;
}Heap;

Heap *initHeap(int n) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (int *)malloc(sizeof(int) * n);
    h->len = 0;
    h->size = n;
    return h;
}

void freeHeap(Heap *h) {
    if (!h)
        return;
    free(h->data);
    free(h);
    return;
}

void up_upAdj(Heap *h, int ind) {
    if (ind == 0) return;
    if (h->data[ind] > h->data[ind  >> 1]) {
        swap(h->data[ind], h->data[ind  >> 1]);
        up_upAdj(h, ind >> 1);
    }
}
int push(Heap *h, int val) {
    if (!h)
        return 0;
    if (h->len == h->size) {
        return 0;
    }
    h->data[h->len] = val;
    up_upAdj(h, h->len);
    h->len++;
    return 1;
}

void downAdj(int *arr, int idx, int len) {
    while(idx * 2 + 1 < len) {
        int tmp = idx, l = idx * 2 + 1, r = idx * 2 + 2;
        if (arr[l] > arr[tmp]) {
            tmp = l;
        }
        if (r < len && arr[r] > arr[tmp]) {
            tmp = r;
        }
        if (tmp == idx) 
            break;

        swap(arr[idx], arr[tmp]);

        idx = tmp;
    }
    return;
}

int isEmpty(Heap *h) {
    return !h || h->len == 0;
}

int pop(Heap *h) {
    int res = h->data[0];
    h->data[0] = h->data[h->len - 1];
    h->len--;

    downAdj(h->data, 0, h->len);
    return res;
}
void showHeap (Heap *h) {
    printf("Heap[");
    for (int i = 0; i < h->len; i++) {
        if (i != 0) printf(", ");
        printf("%d", h->data[i]);
    }

    printf("]\n");
}
int main() {
    srand(time(0));
    int cnt = 10;
    Heap *h = initHeap(10);
    while (cnt--) {
        int val = rand() % 100;
        push(h, val);
    }
    showHeap(h);

    printf("pop[");
    while(!isEmpty(h)) {
        printf("%d ", pop(h));
    }
    printf("]\n");

    freeHeap(h);
    return 0;
}
