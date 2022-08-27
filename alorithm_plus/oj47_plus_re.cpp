/*************************************************************************
	> File Name: oj47_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 04:32:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans[10005], n, V;
int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
            for (int k = V; k >= w; k--) {
                ans[k] = max(ans[k], v + ans[k - w]);
            }
    } 
    cout << ans[V] << endl;
    return 0;
}
