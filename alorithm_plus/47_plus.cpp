/*************************************************************************
	> File Name: 47.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2022 10:46:08 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, V, ans[10005], v, w;
int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w >> v;
        for (int j = V; j >= w; j--) {
            ans[j] = max(ans[j], v + ans[j - w]); 
        }
    }
    cout << ans[V] << endl;
    return 0;
}
