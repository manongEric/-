/*************************************************************************
	> File Name: oula30.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Feb 2022 04:58:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[15], ans;
void init() {
    num[1] = 1;
    for (int i = 2; i <= 9; i++) {
        int t = i;
        for (int j = 0; j < 4; j++) {
            t *= i;
        }
        num[i] = t;
    }
    return;
}
int func(int x) {
    int n = 0, temp = x;
    while (x) {
        n += num[x % 10];
        x /= 10;
    }
    return temp == n;
}
int main() {
    init();
    for (int i = 2; i < 1000000; i++) {
        if (func(i)) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
