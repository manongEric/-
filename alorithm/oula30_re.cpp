/*************************************************************************
	> File Name: oula30_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 07:39:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[10], ans;
void init(int *num) {
    for (int i = 1; i <= 9; i++) {
        int t  = i;
        for (int j = 0; j < 4; j++) {
            t *= i;
        }
        num[i] = t;
    }
    cout << num[5] << endl;
}
int func(int x) {
    int t = x, a = 0;
    while (x) {
        a += num[x % 10];
        x /= 10;
    }
    return a == t;
}
int main() {
    init(num);
    for (int i = 2; i < 1000000; i++) {
        if (func(i)) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
