/*************************************************************************
	> File Name: oula32_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 07:11:19 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int check[10005], ans;
int digit(int x) {
    return floor(log10(x)) + 1;
}
int work(int *mark, int n) {
    while (n){
        if (mark[n % 10] == 1) {
            return 0;
        } else {
            mark[n % 10] = 1;
        }
        n /= 10;
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
    for (int i = 2; i < 99; i++) {
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
