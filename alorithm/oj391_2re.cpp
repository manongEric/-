/*************************************************************************
	> File Name: oj390_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 02:54:37 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
long long  n, m, rawl, rawr;
long long num[100005];
int func(long long x) {
    int temp = 0, last = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + num[i] <= x) {
            sum += num[i];
        } else {
            sum = 0;
            temp++;
            sum += num[i];
        }
    }
    if (sum != 0) {
        temp++;
    }
    return temp;
}
long long bs() {
    long long l = rawl, r = rawr;
    while (l != r) {
        long long mid = (l + r) >> 1;
        long long t = func(mid);
        if (t <= m) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
        rawl = max(rawl, num[i]);
        rawr += num[i];
    }
 //   cout << func(6) << endl;
    printf("%lld\n", bs());
    return 0;
}
