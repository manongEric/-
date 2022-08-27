/*************************************************************************
	> File Name: oula33.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Feb 2022 03:45:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int func (int a, int b) {
    int x1 = a % 10, x2 = a / 10, y1 = b % 10, y2 = b / 10;
    if (!x1 || !x2 || !y1 || !y2) return 0;
    if (x1 == y1 && x2 * b == y2 * a) return 1;
    if (x1 == y2 && x2 * b == y1 * a) return 1;
    if (x2 == y1 && x1 * b == y2 * a) return 1;
    if (x2 == y2 && x1 * b == y1 * a) return 1;
    return 0;
}
int main() {
    int ans1 = 1, ans2 = 1;
    for (int i = 11; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (func(i, j)) {
                ans1 *= i;
                ans2 *= j;
            }
        }
    }
    int t = gcd(ans1, ans2);
    cout << ans2 / t << endl;
    return 0;
}
