/*************************************************************************
	> File Name: oj49_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 07:22:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans[100005], V, n, w, v, s;
int main() {
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        cin >> w >> v >> s;
        for (int j = 1; s > 0; s -= j, j *= 2) {
            j = min(s, j);
            for (int k = V; k >= w * j; k--) {
                ans[k] = max(ans[k], v * j + ans[k - j * w]);
            }
        }
    }
    cout << ans[V] << endl;
    return 0;
}
