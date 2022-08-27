/*************************************************************************
	> File Name: 47.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2022 10:46:08 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, V, ans[105][100005], w[105], v[105];
int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        for (int j = 1; j <= V; j++) {
            if (j < w[i]) {
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], v[i] + ans[i - 1][j - w[i]]);
            }
        }
    }
    cout << ans[n][V] << endl;
    return 0;
}
