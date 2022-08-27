/*************************************************************************
	> File Name: oula2.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Feb 2022 09:20:36 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans;
int main() {
    int a = 1, b = 2;
    while (b <= 4000000) {
        if (b % 2 == 0) {
            ans += b;
        }
        b = a + b;
        a = b - a;
        
    }
    cout << ans << endl;
    return 0;
}
