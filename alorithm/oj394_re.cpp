/*************************************************************************
	> File Name: oj394_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Mar 2022 04:15:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ll, n, m;           
int raw = 2100000000;
int num[50005];
int func(int x) {
    int last = 0, ans = 0;;
    for (int i = 1; i <= n + 1; i++) {
        if (num[i] - last < x) {
            ans++;
        }
        else {
            last = num[i];
        }
    }
    return ans;
}
int bs() {
    int l = raw, r = ll;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int t = func(mid);
        if (t <= m) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {          
    cin >> ll >> n >> m;
    num[0] = 0;
    num[n + 1] = ll;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        raw = min(num[i]- num[i - 1], raw);
    }
    raw = min(raw, ll - num[n]);
    cout << bs() << endl;
    return 0;
}
