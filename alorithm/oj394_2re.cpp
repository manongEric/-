/*************************************************************************
	> File Name: oj394_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 04:50:31 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int ll, n, m, num[500005],rawl = 999999999, rawr;
int func(int x) {
    int t = 0, last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (num[i] - num[last] < x) {
            t++;
        } else {
            last = i;
        }
    }
    return t;
}
int bs() {
    int l = rawl, r = ll;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int t = func(mid);
        if (t <= m) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    scanf("%d%d%d", &ll, &n, &m);
    num[n + 1] = ll;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        rawl = min(rawl, num[i] - num[i - 1]);
    }
    rawl = min(num[n + 1] - num[n], rawl);
    printf("%d\n", bs());
    return 0;
}
