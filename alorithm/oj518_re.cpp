/*************************************************************************
	> File Name: oj518_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Mar 2022 09:34:06 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, total, now = 1, ans;
int main() {
    cin >> n;
    while (1) {
        if (total == n) {
            break;
        }
        for (int i = 0; i < now; i++) {
            ans += now;
            total++;
            cout << total << endl;
        }
        now++;
    }
    cout << ans << endl;
    return 0;
}
