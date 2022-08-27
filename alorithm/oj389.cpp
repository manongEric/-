/*************************************************************************
	> File Name: oj389.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Feb 2022 07:39:54 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int num[100005], n, m;
int func (int x) {
    int last = num[0], t = 1;
    for (int i = 1; i < n; i++) {
        if (num[i] - last >= x) {
            last = num[i];
            t++;
        }
    }
    return t;
}
int bs() {
    int l = 1, r = num[n - 1] - num[0];
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        if (func(mid) >= m) {
            l  = mid;
        }else {
            r = mid - 1;
        }
    }
    return l;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    cout << bs() << endl;
    return 0;
}

