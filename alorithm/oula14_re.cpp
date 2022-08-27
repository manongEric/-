/*************************************************************************
	> File Name: oula14_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Feb 2022 12:47:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans, now;
long long num[10000005];
long long func(long long x) {
    if (x == 1) {
        return 1;
    }
    if (x <= 10000000 && num[x]) {
        return num[x];
    }
    long long  t;
    if (x % 2 == 0) {
        t = func(x / 2) + 1;
    }else {
        t = func(x * 3 + 1) + 1;
    }
    if (x <= 10000000) {
        num[x] = t;
    }
    return t;
}
int main() {
    for (int i = 1; i < 1000000; i++) {
        if (ans < func(i)) {
            ans = func(i);
            now = i;
        }
    }
    cout << now << endl;
    return 0;
}
