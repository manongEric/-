/*************************************************************************
	> File Name: 47.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2022 10:46:08 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, V, ans[100005], w, v, s;
int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w >> v >> s;
        for (int j = 1; s > 0; s -= j, j *= 2){
            j = min(s, j);
            for (int k = V; k >= w * j; k--) {
                ans[k] = max(ans[k], j * v + ans[k - w * j]);
            }
        }
    }
    cout << ans[V] << endl;
    return 0;
}
