/*************************************************************************
	> File Name: oula13_puls_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Feb 2022 06:15:44 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
char s1[1005],s2[1005];
int num1[1005], num2[1005], ans[2005];
int main() {
    cin >> s1 >> s2;
    num1[0] = strlen(s1);
    num2[0] = strlen(s2);
    for (int i = 0, j = num1[0]; s1[i]; i++, j--) {
        num1[j] = s1[i] - '0'; 
    }
    for (int i = 0, j = num2[0]; s2[i]; i++, j--) {
        num2[j] = s2[i] - '0'; 
    }

    ans[0] = num1[0] + num2[0] - 1;
    for (int i = 1; i <= num1[0]; i++) {
        for (int j = 1; j <= num2[0]; j++) {
            ans[i + j - 1] += num1[i] * num2[j];
        }
    }

    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] > 9) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == ans[0]) {
                ans[0]++;
            }
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
