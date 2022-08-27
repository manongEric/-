/*************************************************************************
	> File Name: oj47_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 04:32:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans[105][10005], n, V, w[105], v[105];
int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= V; k++) {
                if (k < w[j]) {
                    ans[j][k] = ans[j - 1][k];
                } else {
                    ans[j][k] = max(ans[j - 1][k], v[j] + ans[j - 1][k - w[j]]);
                }
            }
        }
    
    cout << ans[n][V] << endl;
    return 0;
}
