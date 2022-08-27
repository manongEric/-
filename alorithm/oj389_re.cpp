/*************************************************************************
	> File Name: oj389_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Mar 2022 09:54:45 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int num[100005], m, n;
int func(int x) {
    int dis = 1, last = num[0];
    for (int i = 1; i < m; i++) {
        if (num[i] - last >= x) {
            last = num[i];
            dis++;
        }
    }
    return dis;
}
int bs() {
    int l = 1, r = num[m - 1] - num[0];
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int t = func(mid);
        if (t < n) {
            r = mid - 1;
        }else {
            l = mid;
        }
    }
    return r;
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }
    sort(num, num + m);
    cout << bs() << endl;
    return 0;
}

