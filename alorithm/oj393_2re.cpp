/*************************************************************************
	> File Name: oj390_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 02:54:37 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n, m; 
double raw;
double num[100005];
int func(double x) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += num[i] / x;
    }
    return temp;
}
double bs() {
    double l = 0, r = raw;
    while (fabs(l - r) > 0.00005) {
        double mid = (l + r ) / 2.0;
        int t = func(mid);
        if (t >= m) l = mid;
        else r = mid;
    }
    return l;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        raw = max(raw, num[i]);
    }
    double s = bs();
    printf("%.2lf\n", s - 0.005);
    return 0;
}
