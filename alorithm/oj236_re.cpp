/*************************************************************************
	> File Name: oj236_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 03:00:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, cnt = 1, num[15];
void print() {
    for (int i = 1; i <= m; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}
void func(int s, int left) {
    if (left == 0) {
        print();
        return;
    }
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
}
int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
