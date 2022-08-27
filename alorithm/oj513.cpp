/*************************************************************************
	> File Name: oj513.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 04:20:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int m, t, ans; 
int func(int x) {
    while (x) {
        if (x % 10 == t) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}
int main() {
    cin >> m >> t;
    for (int i = 1; i <= m; i++) {
        if (func(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

