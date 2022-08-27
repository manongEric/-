/*************************************************************************
	> File Name: oj82.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Feb 2022 08:55:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[1000005], n, m, l = 0, r;
int func(int x) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x <= num[i]) {
            ans += num[i] - x;
        }
    }
    return ans;
}
int bs() {
    while (l != r) {
        cout << l << " " << r << endl;
        int mid = (l + r) >> 1;
        if (func(mid) >= m) {
            l = mid + 1;
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
        r = max(num[i], r);
    }
    cout << bs() << endl;
    return 0;
}
