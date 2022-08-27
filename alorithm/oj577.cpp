/*************************************************************************
	> File Name: oj577.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Mar 2022 07:49:53 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;
int cnt;
string ans;
int main() {
    map<string, int> m;
    string t;
    while (cin >> t) {
        for (int i = 0; i < t.size(); i++) {
            if (t[i] >= 'A' && t[i] <= 'Z') {
                t[i] += 'a' - 'A';
            }
        }
        m[t]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > cnt) {
            ans = it->first;
            cnt = it->second;
        }
    }
    cout << ans << " " << cnt << endl;
    return 0;
}

