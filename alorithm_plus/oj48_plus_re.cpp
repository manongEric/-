/*************************************************************************
	> File Name: oj47.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Feb 2022 10:08:38 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, V, ans[10005], w[10005], v[10005];
int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= V; j++) {
                if (j >= w[i]){
                    ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
                }
            }
        }
    
    cout << ans[V] << endl;


    return 0;
}
