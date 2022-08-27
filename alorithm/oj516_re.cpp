/*************************************************************************
	> File Name: oj516_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Mar 2022 09:04:39 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, numc[100005], numw[100005];
long long ans;
string s;
int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            numc[i] += (s[i] == 'C');
        }else {
            numc[i] += numc[i - 1] + (s[i] == 'C');
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            numw[i] += (s[i] == 'W');
        }else {
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
