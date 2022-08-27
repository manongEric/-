/*************************************************************************
	> File Name: linear_table.c
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Apr 2022 09:58:31 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Vector {
    int *data;
    int size;
    int length;
}Vec;
Vec *init(int n) {
    Vec *v = (Vec *)malloc(sizeof(Vec));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}
void freeVec(Vec *v) {
    if (v == NULL) {
        return;
    }
    free(v->data);
    free(v);
    return;
}
int expand(Vec *v) {
    if (!v) {
        return 0;
    }
    int expsize = v->size;
    int *tmp;
    while (expsize) {
        tmp = (int *)realloc(v->data, sizeof(int)*(v->size + expsize));
        if (tmp) {
            v->data = tmp;
            break;
        }
        expsize /= 2;
    }
    if (!tmp) {
        return 0;
    }

    v->size += expsize; 
    printf("expand %d Byte successfully~~~, new size %d BYte\n", expsize, v->size);

    return 1;
}
int insert(Vec *v, int idx, int val) {
    if (!v) {
        return 0;
    }

    if (idx < 0 || idx > v->length) {
        return 0;
    }

    if (v->length == v->size) {
       if (!expand(v)) {
            printf("expand unsuccessfully\n");
            return 0;
        }
    }

    memcpy(v->data + idx + 1, v->data + idx, sizeof(int) * (v->length - idx));
    v->data[idx] = val;
    v->length++;

    return 1;
}

int erase(Vec *v, int idx) {
    if (!v) {
        return 0;
    }
    
    if (idx < 0 || idx >= v->length) {
        return 0;
    }

    memcpy(v->data + idx, v->data + idx + 1, sizeof(int) * (v->length - idx - 1));
    v->length--;
    return 1;
}

void showVec(Vec *v) {
    printf("Vector: [");
    if (v) {
        for (int i = 0; i < v->length; i++) {
            if (i != 0) printf(", ");
            printf("%d", v->data[i]);
        }
    }
    printf("]\n");
}
int find(Vec *v, int val) {
    if (!v) {
        return -1;
    }
    for (int i = 0; i < v->length; i++) {
        if (v->data[i] == val) {
            return i;
        }
    }
    return -1;
}
int main() {
    int cnt = 20;
    Vec *v = init(1);
    showVec(v);
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
