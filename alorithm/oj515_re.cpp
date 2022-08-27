/*************************************************************************
	> File Name: oj515_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Mar 2022 08:38:40 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int a, b;
int ans1, ans2;
int l;
int main() {
    cin >> a >> b >> l;
    double ans = 99999999;
    double t1 = (double)a / b;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            double t2 = (double)i / j;
            if (t2 >= t1 && t2 - t1 < ans) {
                ans = t2 - t1;
                ans1 = i;
                ans2 = j;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
