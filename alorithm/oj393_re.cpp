/*************************************************************************
	> File Name: oj393_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Mar 2022 10:20:03 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
double num[100005];
int n, k;
double mmax;
int func(double x) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += num[i] / x;
    }
    return t;
}
double bs() {
    double l = 0, r = mmax;
    while (r - l > 0.00005) {
        double mid = (l + r) / 2.00;
        if (func(mid) >= k)  l = mid;
        else r = mid;
    }
    return r;
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    sort(num, num + n);
    double ans = bs();
    printf("%.2f\n", ans - 0.005);
    return 0;
}

