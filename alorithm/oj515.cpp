/*************************************************************************
	> File Name: oj515.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 04:55:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int a, b, l, ans1, ans2;
int main() {
    cin >> a >> b >> l;
    double ans = 99999;
    double raw =(double)a / b;
   // cout << raw << " rwa " << endl;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            double t = (double)i / j;
            if (t >= raw && t - raw < ans) {
                 //   cout << t << endl;
                    ans = t - raw;
                  //  cout << ans << endl;
                    ans1 = i;
                    ans2 = j;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
