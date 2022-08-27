/*************************************************************************
	> File Name: oj237_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 08:32:49 PM CST
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
            mark[i] = 0;
            cnt--;
        }
    }
}
int main() {
    cin >> n;
    func();
    return 0;
}
