/*************************************************************************
	> File Name: oj518.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 08:34:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long ans;
int n, totol, now = 1;;
int main() {
    cin >> n;
    while (1) {
        for (int i = 0; i < now; i++) {
            ans += now;
            totol++;
            if (totol == n) {
                cout << ans << endl;
                return 0;
            }
        }
        now++;
    }

    return 0;
}
