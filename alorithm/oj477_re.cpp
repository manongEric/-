/*************************************************************************
	> File Name: oj477_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Mar 2022 11:58:08 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string s;
int main() {
    cin >> s;
    int last = -1, ans = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U') {
            if (last == -1) {
                last = i;
            }else {
                ans = max(i - last, ans);
                last = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}


