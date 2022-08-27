/*************************************************************************
	> File Name: oula32.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Feb 2022 02:45:20 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int  ans;
int check[10005]; 
int digit(int x) {
    return floor(log10(x)) + 1;
}
int work(int *mark, int n) {
    while (n) {
        int t = n % 10;
        if (mark[t] == 1) {
            return 0;
        }
        mark[t] = 1;
        n /= 10;
    } 
    return 1;
}
int func(int x, int y, int z) {
    int mark[10] = {0};
    if (work(mark, x) && work(mark, y) && work(mark, z) && mark[0] == 0) {
        return 1;
    }
    return 0;
}
int main() {
    for (int i = 2; i <= 98; i++) {
        for (int j = i + 1; 1; j++) {
            int a = digit(i), b = digit(j), c = digit(i * j);
            if (a + b + c > 9) {
                break;
            }
            if (a + b + c == 9) {
                if (func(i, j, i * j)) {
                    if (check[i * j] == 0) {
                        check[i * j] = 1;
                        ans += i * j;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
