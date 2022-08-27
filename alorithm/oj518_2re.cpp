/*************************************************************************
	> File Name: oj518_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 04:15:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, now = 1, day, ans;
int main() {
    cin >> n;
    while(1) {
        for (int i = 1; i <= now; i++) {
            ans += now;
            day++;
            if (day == n) {
                break;
            }
        }
        now++;
    }
    cout << ans << endl;
    return 0;
}
