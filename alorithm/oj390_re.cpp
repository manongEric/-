/*************************************************************************
	> File Name: oj390_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 02:54:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, raw;
int num[100005];
long long func(int x) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += num[i] / x;
    }
    return temp;
}
int bs() {
    int l = 1, r = raw;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        long long  t = func(mid);
        if (t >= m) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        raw = max(raw, num[i]);
    }
    cout << bs() << endl;
    return 0;
}
