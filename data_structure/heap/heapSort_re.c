/*************************************************************************
	> File Name: heapSort_re.c
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Apr 2022 06:45:57 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a)__temp = a;\
    a = b;b = __temp;\
}

void downAdj(int *arr, int idx, int len) {
    while (idx * 2 + 1 < len) {
        int temp = idx, l = idx * 2 + 1, r = idx * 2 + 2;
        if (arr[l] > arr[temp]) 
            temp = l;
        

        if (r < len && arr[r] > arr[temp]) 
            temp = r;
        

        if (temp == idx)
            break;
        swap(arr[temp], arr[idx]);

        idx = temp;
    }
    return;
}

void HeapSort(int *arr, int len) {
    for (int i = (len - 2) / 2; i >= 0; i--) {
        downAdj(arr, i, len);
    }

    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        downAdj(arr, 0, i);
    }
    return;
}

void showHeap(int *arr, int len) {
    printf("Heap : ");
    for (int i = 0; i < len; i++) {
        i && printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
    return;
}
int main() {
   /* #define arrlen 10
    int arr[arrlen];


    for (int i = 9; i >= 0; i--) {
        arr[i] = i;
    }*/
    #define arrlen 10
   int  arr[arrlen] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    showHeap(arr, arrlen);
    
    HeapSort(arr, arrlen);
    showHeap(arr, arrlen);
    return 0;
}
