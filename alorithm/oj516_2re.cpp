/*************************************************************************
	> File Name: oj516_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 04:00:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int numc[10005], numw[10005], n, ans;
char s[10005];
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            numc[i] += (s[i] == 'C');
        } else {
            numc[i] += numc[i - 1] + (s[i] == 'C');
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            numw[i] += (s[i] == 'W');
        } else {
            numw[i] += numw[i + 1] + (s[i] == 'W');
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
