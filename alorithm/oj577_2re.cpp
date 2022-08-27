/*************************************************************************
	> File Name: oj577_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 06:47:15 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
map<string, int> m;
string ans;
int cnt;
int main() {
    string s;
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
            cnt = it->second;
            ans = it->first;
        }
    }
    cout << ans << " " << cnt <<endl;
    return 0;
}
