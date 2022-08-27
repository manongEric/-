/*************************************************************************
	> File Name: oj505.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Mar 2022 08:10:17 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string s[100005];
bool cmp (string &a, string &b) {
    return a + b > b + a;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
