/*************************************************************************
	> File Name: oj577_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Mar 2022 10:56:21 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;
string s, ans;
int cnt, ans1;
map<string, int> m;
int main() {
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
        }
        m[s]++;
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

