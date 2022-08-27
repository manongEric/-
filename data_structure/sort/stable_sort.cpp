/*************************************************************************
	> File Name: stable_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 31 Mar 2022 01:14:18 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int num[6] = {6, 5, 4, 3, 2, 1};
void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int pl = l, pr = mid + 1, k = 0;
    while (pl <= mid || pr <= r) {
        if (pr > r || (pl <= mid && num[pl] <= num[pr])) {
            temp[k++] = num[pl++];
        } else {
            temp[k++] = num[pr++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return;
}
void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
}
void bubble_sort(int *num, int n) {
    int flag = 1;
    for (int i = 1; i < n && flag; i++) {
        flag = 0;
        for (int j = 0; j < n - i; j++) {
            if (num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            flag = 1;
        }
    }
}

int main() {
    merge_sort(num, 0, 5);
    for (int i = 0; i < 6; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
