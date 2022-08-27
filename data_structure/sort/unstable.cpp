/*************************************************************************
	> File Name: unstable.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 31 Mar 2022 04:31:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[6] = {6, 5, 4, 3, 2, 1};
void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) {
                ind = j;
                swap(num[ind], num[i]);
            }
        }
    }
}
void quick_sort(int *num, int l, int r) {
    if (l > r) return;
    int x = l, y = r, z = num[x];
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    } 
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return;
}
void quick_2sort(int *num, int l, int r) {
    while(l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        while(x <= y) {
            while (num[x] < z) x++;
            while (num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                x++; y--;
            } 
        }//while (x <= y);
        quick_2sort(num, l, y);
        l = x;
    }
    return;
}
int main() {
    quick_sort(num, 0, 5);
    for (int i = 0; i < 6; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
