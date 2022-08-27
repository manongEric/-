/*************************************************************************
	> File Name: oula32_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Feb 2022 10:35:28 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int ans;
int check[100000];
int work(int *mark, int x) {
    while (x) {
        if (mark[x % 10] == 1) return 0;
            mark[x % 10] = 1;
        x /= 10;
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
int digit(int n) {
    return floor(log10(n)) + 1;
}
int main() {
    for (int i = 2; i < 99; i++) {
        for (int j = i + 1; 1; j++) {
            int a, b, c;
            a = digit(i), b = digit(j), c = digit(i * j);
            if (a + b + c > 9) {
                break;
            }else if (a + b + c == 9) {
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
