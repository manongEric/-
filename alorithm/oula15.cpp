/*************************************************************************
	> File Name: oula15.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Feb 2022 04:50:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long dp[25][25];
int main() {
   /* for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            if (i == 1 && j == 1) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[21][21] << endl;*/
    long long fin = 1;
    for (int i = 40, j = 1; i > 20; i--, j++){
        fin *= i;
        fin /= j;
    }
    cout << fin << endl;
    return 0; 
}
