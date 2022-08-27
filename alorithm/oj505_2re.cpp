/*************************************************************************
	> File Name: oj505_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 02:55:49 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
string s[100005];
int n;
bool cmp(string &a, string &b) {
    return a + b > b + a;
};
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
