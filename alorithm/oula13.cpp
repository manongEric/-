/*************************************************************************
	> File Name: oula13.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Feb 2022 09:08:37 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
char str1[1005], str2[1005];
int num1[1005], num2[1005], sum[1005];
int main() {
    cin >> str1 >> str2;
    num1[0] = strlen(str1);
    num2[0] = strlen(str2);

    for (int i = 0, j = num1[0]; str1[i]; i++, j--) {
        num1[j] = str2[i] - '0';
    }
    for (int i = 0, j = num2[0]; str2[i]; i++, j--) {
        num2[j] = str2[i] - '0';
    }

    sum[0] = max(num1[0], num2[0]);
    for (int i = 1; i <= sum[0]; i++) {
        sum[i] = num1[i] + num2[i];
    }

    for (int i = 1; i <= sum[0]; i++) {
        if (sum[i] > 9) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
            if (i == sum[0]) {
                sum[0]++;
            }
        }
    }

    for (int i = sum[0]; i > 0; i--) {
        cout << sum[i];
    } 
    cout << endl;

    return 0;
}

