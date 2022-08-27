/*************************************************************************
	> File Name: floyd.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Mar 2022 10:51:02 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int n, m, s, arr[1005][1005];
int main() {
    cin >> n >> m >> s;
    memset(arr, 0x3f, sizeof(arr));
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (arr[a][b] > c) {
            arr[a][b] = c;
            arr[b][a] = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    arr[s][s] = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[s][i] == 0x3f3f3f3f) {
            cout << -1 << endl;
        } else {
            cout << arr[s][i] << endl;
        }
    }

    return 0;
}
