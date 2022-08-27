/*************************************************************************
	> File Name: oj237_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 03:59:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[15], mark[15], n, cnt = 1;
void print() {
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << num[i];
    }
    cout << endl;
}
void func() {
    if (cnt == n + 1) {
        print();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
        num[cnt] = i;
        mark[i] = 1;
        cnt++;
        func();
        cnt--;
        mark[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    func();
    return 0;
}
