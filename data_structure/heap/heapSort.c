/*************************************************************************
	> File Name: heapSort.c
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Apr 2022 08:17:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define swap(a, b) {\
    __typeof(a) __tmp = a;\
    a = b; b = __tmp;\
}

void downAdj(int *arr, int idx, int len) {
    while (idx * 2 + 1 < len) {
        int temp = idx, l = idx * 2 + 1, r = idx * 2 + 2;
        if (arr[l] > arr[temp]){
            temp = l;
        }
        if (r < len && arr[r] > arr[temp]){
            temp = r;
        }

        if (temp == idx) 
            break;

        swap(arr[temp], arr[idx]);
        idx = temp;
    }
    return;
}
//数组构建堆O(n), 堆排序O(nlong(n))
void heapSort(int *arr, int len) {
    for (int i = (len - 2) / 2; i >= 0; i--) {
        downAdj(arr, i, len);
    }

    for (int i = len - 1; i > 0; i--) {
        swap(arr[i], arr[0]);
        downAdj(arr, 0, i);
    }
    return;
}

void showArr(int *arr, int len) {
    printf("arr[");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    return;
}

int main() {
    srand(time(0));
    #define arrlen 10
    int arr[arrlen];


    for (int i = 0; i < arrlen; i++) {
        arr[i] = rand() % 100;
    }
    showArr(arr, arrlen);
    
    heapSort(arr, arrlen);
    showArr(arr, arrlen);
    return 0;
}
