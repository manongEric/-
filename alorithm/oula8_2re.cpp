/*************************************************************************
	> File Name: oula8_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 08:02:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
char arr[1005];
int ans, zero_cnt, now;
int main() {
    cin >> arr;
    for (int i = 0; arr[i]; i++) {
        if (arr[i] != '0') {
            now *= arr[i] - '0';
        } else {
            zero_cnt++;
        }
        if (i - 13 >= 0) {
            if (arr[i - 13] != 0) {
                now /= arr[i] - '0';
            } else {
                zero_cnt--;
            }
        }
        if (zero_cnt == 0) {
            ans = max(now, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
