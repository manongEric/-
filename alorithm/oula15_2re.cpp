/*************************************************************************
	> File Name: oula15_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 10:36:07 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long  arr[25][25];
int main() {
    /*for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            if (i == 1 && j == 1) {
                arr[i][j] = 1;
                continue;
            }
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }
    cout << arr[21][21] << endl;*/
    long long fin = 1;
    for (int i = 40, j = 1; i > 20; i--, j++) {
        fin *= i;
        fin /= j;
    }
    cout << fin << endl;
    return 0;
}
