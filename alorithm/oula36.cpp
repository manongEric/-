/*************************************************************************
	> File Name: oula36.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Feb 2022 04:28:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int sum;
int func(int a, int b) {
    int temp = a, t = 0;
    while (a) {
        t = t * b + a % b;
        a /= b;
    }
    return temp == t;
}
int main() {
    for (int i = 1; i < 1000000; i++) {
        if (func(i, 2) && func(i, 10)) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
