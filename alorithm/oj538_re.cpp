/*************************************************************************
	> File Name: oj538_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Mar 2022 10:52:04 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int arr[25][25], mark[25], n, flag;
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
    cout << endl;
    return 0;
}
