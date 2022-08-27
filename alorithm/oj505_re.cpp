/*************************************************************************
	> File Name: oj505_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Mar 2022 12:44:58 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string s[100005];
bool cmp(string &a, string &b) {
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

