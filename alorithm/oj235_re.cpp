/*************************************************************************
	> File Name: oj235_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 02:28:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int cnt = 1, n, num[15];
void print(int x) {
    for (int i = 1; i <= x; i++) {
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
