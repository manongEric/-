/*************************************************************************
	> File Name: oula15_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Feb 2022 06:36:03 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long dp[30][30];
int main() {
    long long  fin = 1;
    for (int i = 40, j = 1; i > 20; i--, j++) {
        fin *= i;
        fin /= j;
    }
    cout << fin << endl;
    /*for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            if (i == 1 && j == 1) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[21][21] << endl;*/
    return 0;
}
