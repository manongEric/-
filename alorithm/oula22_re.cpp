/*************************************************************************
	> File Name: oula22_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Feb 2022 10:19:32 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s[6005];
int n;
long long ans;
int main () {
    while (cin >> s[n]) {
        n++;
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 0; j < s[i].size(); j++) {
            t += s[i][j] - 'A' + 1;
        }
        ans += t * i;
    }
    return 0;
}

