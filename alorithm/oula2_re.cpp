/*************************************************************************
	> File Name: oula2_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 07:37:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans[4000005] = {0, 1};
long long sum;
int main() {
    /*for (int i = 2; 1; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
        if (ans[i] >= 4000000) break;
        if (ans[i] % 2 == 0) {
            sum += ans[i];
        }
    }*/
    int a = 1, b = 2;
    while (b <= 4000000) {
        if (b % 2 == 0) {
            sum += b;
        }
            b = b + a;
            a = b - a;
    }
    cout << sum << endl;
    return 0;
}
