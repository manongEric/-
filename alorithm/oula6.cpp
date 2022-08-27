/*************************************************************************
	> File Name: oula6.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Feb 2022 03:07:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int ans = 0, ans1 = 0;
    for (int i = 1; i <= 100; i++) {
        ans += i * i;
        ans1 += i;
    }
    cout << ans1 * ans1 - ans << endl;
    return 0;
}
