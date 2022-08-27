/*************************************************************************
	> File Name: oj235.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Mar 2022 08:32:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[15], n;
void print(int cnt) {
    for (int i = 1; i <= cnt; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}
void func(int s, int deep) {
    for (int i = s; i <= n; i++) {
        num[deep] = i;
        print(deep);
        func(i + 1, deep + 1);
    }
    return;
}
int main() {
    cin >> n;
    func(1, 1);
    return 0;
}
