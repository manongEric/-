/*************************************************************************
	> File Name: floyd_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Mar 2022 01:15:37 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int n, m, arr[1005][1005], s;
int main() {
    memset(arr, 0x3f, sizeof(arr));
    cin >> n >> m >> s;
    arr[s][s] = 0;
    for (int i = 0; i < m; i++) {
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
    
    for (int i = 1; i <= n; i++) {
        if (arr[s][i] == 0x3f3f3f3f) {
            cout << -1 << endl;
        } else {
            cout << arr[s][i] << endl;
        }
    }
    return 0;
}

