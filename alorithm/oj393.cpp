/*************************************************************************
	> File Name: oj393.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Feb 2022 08:27:41 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double num[100005];
int n, m;
double r = 0, l = 0;
int func(double x) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += num[i] / x;
    }
    return t; 
}
double bs() {
    while(fabs(l - r) > 0.0005) {
        double mid = (l + r) / 2;
        if (func(mid) >= m) {
            l= mid;
        }else {
            r = mid;
        }
    }
    return r;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        r = max(r, num[i]);
    }
    double ans = bs();
  //  printf("%.2f\n", (int)(ans * 100) / 100.0);
    printf("%.2f\n", ans - 0.005);
    return 0;
}

