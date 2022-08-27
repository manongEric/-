/*************************************************************************
	> File Name: oula22.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Feb 2022 01:46:52 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string name[6005];
int n;
int main() {
    while (cin >> num[n]) {
        n++;
    }
    sort(name, name + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < name[i].size(); j++) {
            t += num[i][j] - 'A' + 1;
        }
        ans += (i + 1) * t; 
    }
    return 0;
}

