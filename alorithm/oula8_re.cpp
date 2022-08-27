/*************************************************************************
	> File Name: oula8_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Feb 2022 11:05:45 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
char s[1005];
int num[1005];
int now = 1, ans, zero_cnt;

int main() {
    cin >> s;
    for (int i = 0; s[i]; i++) {
      //  if (i < 13){
        //    now *= s[i] - '0';
       // }
       // if (i >= 13) {
            if (s[i] != '0') {
                now *= s[i] - '0';
            }else {
                zero_cnt++;
            }
        if (i >= 13) {
            if (s[i - 13] != '0') {
                now /= s[i - 13] - '0';
            }else {
                zero_cnt--;
            }
        }
        if (zero_cnt == 0) {
            ans = max(ans, now);
        }

       // }
    }

    cout << ans << endl;
    return 0;
}
