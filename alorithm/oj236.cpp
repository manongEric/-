/*************************************************************************
	> File Name: oj235.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Mar 2022 08:32:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[15], n, m, cnt = 1;
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
        num[cnt] = i;
        cnt++;
        func(i + 1, left - 1);
        cnt--;
    }
    return;
}
int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
