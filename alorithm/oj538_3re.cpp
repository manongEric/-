/*************************************************************************
	> File Name: oj538_3re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 10:48:43 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int arr[25][25], mark[30], n, flag;
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
