/*************************************************************************
	> File Name: oj235_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 08:16:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int cnt = 1, n, num[15];
void print(int m) {
    for (int i = 1; i <= cnt; i++) {
        if (i != 1) cout << " ";
        cout << num[i];
    }
    cout << endl;
}
void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt] = i;
        print(cnt);
        cnt++;
        func(i + 1);
        cnt--;
    }
}
int main() {
    cin >> n;
    func(1);
    return 0;
}
