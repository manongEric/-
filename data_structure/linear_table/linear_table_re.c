/*************************************************************************
	> File Name: linear_table_re.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Aug 2022 02:30:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct Vector{
    int *data;
    int length;
    int size;
}Vec;

Vec* initVector(int n) {
    Vec* v = (Vec*)malloc(sizeof(Vec));
    v->data = (int*)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

void freeVec(Vec* v) {
    if (!v) return;
    free(v->data);
    free(v);
    return;
}
int expand(Vec* v) {
    int expsize = v->size;
    int *temp;
    while (expsize) {
        temp = (int*)realloc(v->data, sizeof(int)* (v->size + expsize));
        if (temp) {
            v->data = temp;
            break;
        }
        expsize /= 2;
    }
    if (!temp) return 0;
    v->size += expsize;
    printf("Expand sucecessfully, expand size = %d , new size is %d \n", expsize, v->size);
    return 1;
}
int insert(Vec* v, int index, int val) {
    if (!v)
        return 0;
    if (index < 0 || index > v->length)
        return 0;
    if (v->length == v->size){
        if (!expand(v))
            return 0;
    }

    memcpy(v->data + index + 1, v->data + index, sizeof(int) * (v->length - index));
    v->data[index] = val;
    v->length++;
    return 1;
}

int erase(Vec* v, int index) {
    if (!v)
        return 0;
    
    if (index < 0 || index >= v->length)
        return 0;

    memcpy(v->data + index, v->data + index + 1, sizeof(int) * (v->length - index - 1));
    v->length--;
    return 1;
}

void showVec(Vec* v) {
    printf("Vector :[");
    if (v) {
        for (int i = 0; i < v->length; i++) {
            i && printf(", ");
            printf("%d",v->data[i]);
        }
    }
    printf("]\n");
}

int main() {
    int cnt = 20;
    Vec *v = initVector(2);
    srand(time(0));
    while (cnt--) {
        int opt = rand() % 4;
        int val = rand() % 100;
        int idx = rand() % (v->length + 3) - 1;// [-1, v->length + 1]
        switch(opt) {
            case 0:
            case 1:
            case 2:
                printf("insert %d at %d index, res = %d\n", val, idx, insert(v, idx, val));
                break;
            case 3:
                printf("erase %d index, res = %d\n",idx, erase(v, idx));
                break;
        }
        showVec(v);
    }
    freeVec(v);
    return 0;
}
