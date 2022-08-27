/*************************************************************************
	> File Name: oj538.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Mar 2022 04:26:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, flag, mark[25], arr[25][25];
void func(int x) {
    if (flag == 1) {
        cout << "-";
    }
    flag = 1;
    cout << x;
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0 && arr[i][x] == 1) {
            mark[i] = 1;
            func(i);
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            func(i);
        }
    }
    return 0;
}
