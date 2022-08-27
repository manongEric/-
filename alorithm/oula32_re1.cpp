/*************************************************************************
	> File Name: oula32_re1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Mar 2022 09:17:34 AM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int check[10005];
int ans;
int digit(int n) {
    return floor(log10(n)) + 1;
}
int work(int *mark, int x) {
    while (x) {
        if (mark[x % 10] == 1) {
            return 0;
        }
        mark[x % 10] = 1;
        x /= 10;
    } 
    return 1;
}
int func(int a, int b, int c) {
    int mark[10] = {0};
    if (work(mark, a) && work(mark, b) && work(mark, c) && mark[0] == 0) {
        return 1;
    }
    return 0;
}
int main() {
    for (int i = 1; i < 99; i++) {
        for (int j = i + 1; 1; j++) {
            if (digit(i) + digit(j) + digit(i * j) > 9) {
                break;
            }
            if (digit(i) + digit(j) + digit(i * j) == 9) {
                if (func(i, j, i * j) && check[i * j] == 0) {
                    check[i * j] = 1;
                    ans += i * j;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
