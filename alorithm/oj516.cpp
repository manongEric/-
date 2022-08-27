/*************************************************************************
	> File Name: oj516.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 07:41:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
char s[100005];
int numc[100005], numw[100005], n;
long long ans;
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            numc[i] = (s[i] == 'C');
        }else {
            numc[i] = numc[i - 1] + (s[i] == 'C'); 
        }
    }

    for (int j = n - 1; j >= 0; j--) {
        if (j == n - 1) {
            numw[j] = (s[j] == 'W');
        }else {
            numw[j] = numw[j + 1] + (s[j] == 'W');
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') {
            ans += numc[i] * numw[i];
        }
    }
    cout << ans << endl;
    return 0;
}
