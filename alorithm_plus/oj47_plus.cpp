/*************************************************************************
	> File Name: oj47.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Feb 2022 10:08:38 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, all, v[105], w[105], ans[10005];

int main() {
    cin >> all >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = all; j >= 1; j--) {
            if (j >= v[i]){
                ans[j] = max(ans[j], w[i] + ans[j - v[i]]);
            }
        }
    }
    cout << ans[all] << endl;


    return 0;
}
