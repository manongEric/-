/*************************************************************************
	> File Name: oula13.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Feb 2022 03:33:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long now, ans;
int zero_cnt;
char str[1005];
int main(){
    cin >> str;
    for (int i = 0; str[i]; i++) {
        if (str[i] != '0') {
            now *= str[i] - '0';
        }else {
            zero_cnt++;
        }
        if (i >= 13) {
            if (str[i - 13] != '0') {
                now /= str[i - 13] - '0';
            }else {
                zero_cnt--;
            }
        }
        if (zero_cnt == 0) {
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
