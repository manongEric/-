/*************************************************************************
	> File Name: fib2.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Feb 2022 04:33:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long num[50];
long long  func(int x) {
    if (x == 1 || x == 0) {
        return 1;
    }
    if (num[x] != 0) {
        return num[x];
    }
    return num[x] = func(x - 1) + func(x - 2);
}
int main() {
    for (int i = 0; i < 50; i++) {
        cout << i << " : " << func(i) << endl;
    }
    return 0;
}
