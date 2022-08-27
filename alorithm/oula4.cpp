/*************************************************************************
	> File Name: oula4.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Feb 2022 02:27:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int func(int x) {
    int temp = x, t = 0;
    while(x) {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return t == temp;
}
int ans;
int main() {
    int i, j;
    for (i = 999; i >= 100; i--) {
        for (j = i; j >= 100; j--) {
            if (func(i * j)) {
               ans = max(ans, i * j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
