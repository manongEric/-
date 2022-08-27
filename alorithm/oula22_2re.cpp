/*************************************************************************
	> File Name: oula22_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 06:42:40 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int n;
long long ans;
string str[6000];
int main() {
    while (cin >> str[n]) {
        n++;
    }
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < str[i].size(); j++) {
            t += str[i][j] - 'A' + 1;
        }
        ans += (i + 1) * t;
    }

    return 0;
}
