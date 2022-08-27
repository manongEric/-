/*************************************************************************
	> File Name: oj390.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Feb 2022 04:17:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[100005], n, m, l = 1, r = 0;
int func(int x) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += num[i] / x;
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        r = max(r, num[i]);
    }
    while(l != r) {
        int mid = (l + r + 1) / 2;
        if (func(mid) >= m) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << l << endl;

    return 0;
}
