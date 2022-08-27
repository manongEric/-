/*************************************************************************
	> File Name: oj49.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Feb 2022 07:58:30 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans[100005];
int main() {
    int n, v, w, s, V;
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        cin >> v >> w >> s;
        for (int j = 1; s > 0; s -= j, j *= 2) {
            j = min(s, j);
            for (int k = V; k >= j * v; k--) {
                ans[k] = max(ans[k],j * w + ans[k - j * v]);
            }
        }
    }
    cout << ans[V] << endl;
    return 0;
}
