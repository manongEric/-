/*************************************************************************
	> File Name: oj514_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 03:34:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, cnt, num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int func(int x) {
    if (x == 0) {
        return 6;
    }
    int t = 0;
    while (x) {
        t += num[x % 10];
        x /= 10;
    }
    return t;
}
int main() {
    cin >> n;
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            if (func(i) + func(j) + 4 + func(i + j) == n) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
