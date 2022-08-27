/*************************************************************************
	> File Name: oj503.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Mar 2022 06:57:56 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int ans, num[30005], w, n;
int main () {
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    int l = 0, r = n - 1;
    while (l < r) {
        if (num[l] + num[r] > w) {
            r--;
            ans++;
        }else {
            r--;
            l++;
            ans++;
        }
    }
    if (l == r) ans++;
    cout << ans << endl;
    return 0;
}

