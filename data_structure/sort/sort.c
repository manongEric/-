/*************************************************************************
	> File Name: stable_sort_re.c
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Apr 2022 07:41:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define swap(a, b) {\
    __typeof(a)__temp = a;\
    a = b; b = __temp;\
}
#define TEST(arr, n, func, args...) {\
    int *brr = (int *)malloc(sizeof(int) * n);\
    memcpy(brr, arr, sizeof(int) * n);\
    func(args);\
    printf("%s = ", #func);\
    showArr(brr, n);\
    free(brr);\
}
//插入排序 O(n2)
void insertSort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0, arr[j - 1] > arr[j]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

void bubbleSort(int *arr, int len) {
    int flag = 1;
    for (int i = 1; i < len && flag; i++) {
        flag = 0;
        for (int j = 0; j < len - i; j++) {
            if (arr[j] > arr[j + 1]) {
               swap(arr[j], arr[j + 1]);
               flag = 1; 
            }
        }
    }
}
void showArr(int *arr, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        i && printf(",");
        printf("%d", arr[i]);
    }
    printf("]\n");
    return;
} 

void mergeSort(int *arr, int l, int r) {
    if (l == r)
        return;
    
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int k = 0, p1 = l, p2 = mid + 1;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || p1 <= mid && arr[p1] < arr[p2]) {
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
        }
    }
    memcpy(arr + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return;
}

void selectSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[ind] > arr[j]) {
                ind = j;
            }
        }
        swap(arr[ind], arr[i]);
    }
}
void quickSort(int *arr, int l, int r) {
    if (l > r) 
        return;
    int x = l, y = r, z = arr[x];
    while(x < y) {
        while(x < y && arr[y] > z) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] < z) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quickSort(arr, l, x - 1);
    quickSort(arr, x + 1, r);
    return;
}
void quick2Sort(int *arr, int l, int r) {
    while (l < r) {
        int x = l , y = r, z = arr[(l + r) / 2];
        do {
            while (arr[x] < z) {
                x++;
            }
            while (arr[y] > z) {
                y--;
            }
            if (x <= y) {
                swap(arr[x], arr[y]);
                x++;
                y--;
            }
        } while(x <= y);
        quick2Sort(arr, l, y);
        l = x;
    }
    return;
}
int main() {
    srand(time(NULL));

    #define arrlen 10
    int arr[arrlen];
    for (int i = 0; i < arrlen; i++) {
        arr[i] = rand() % 100;
    }
    
    showArr(arr, arrlen);

    TEST(arr, arrlen, insertSort, brr, arrlen); 
    TEST(arr, arrlen, bubbleSort, brr, arrlen); 
    TEST(arr, arrlen, mergeSort, brr, 0, arrlen - 1);
    TEST(arr, arrlen, selectSort, brr, arrlen);
    TEST(arr, arrlen, quickSort, brr, 0, arrlen - 1);
    TEST(arr, arrlen, quick2Sort, brr, 0, arrlen - 1);
    #undef arrlen

    return 0;
}
