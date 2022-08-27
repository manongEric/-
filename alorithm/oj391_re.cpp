/*************************************************************************
	> File Name: oj391_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Mar 2022 11:10:33 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, num[100005], mmax = 0, sum;
long long func(int x) {
    long long now = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (now + num[i] > x) {
            ans++;
            now = num[i];
        }else if (now + num[i] < x) {
            now += num[i];
        }else {
            ans++;
            now = 0;
        }
    }
    if (now != 0) {
        ans++;
    }
    return ans;
}
int bs() {           
    long long l = mmax, r = sum;
    while (l != r) { 
        int mid = (l + r) / 2;
        long long t = func(mid);
        if (t <= m)  r = mid;
        else {
            l = mid + 1;
        }
    }
    return l;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
        sum += num[i];
    }
    cout << bs() << endl;
}
