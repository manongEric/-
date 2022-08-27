/*************************************************************************
	> File Name: oj515_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 03:51:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
double a, b, l;
int ans1, ans2;
int main() {
    cin >> a >> b >> l;
    double raw = a / b;
    double ans = 999999999;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            double t = (double)i / j;
            if (t >= raw && t - raw < ans) {
                ans = t - raw;
                ans1 = i;
                ans2 = j;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
