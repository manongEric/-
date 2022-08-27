/*************************************************************************
	> File Name: oj477.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Mar 2022 10:57:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans, last = -1;
int main() {
    char s[105];
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'I') {
            if (last == -1) {
                last = i;
            } else {
                ans = max(ans, i - last);
                last = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
