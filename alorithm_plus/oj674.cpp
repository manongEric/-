/*************************************************************************
	> File Name: oj674.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Mar 2022 02:54:04 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int arr[105][105], n, m, degree[105];
int main() {
    memset(arr, 0x3f, sizeof(arr));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 0x3f3f3f3f) {
                degree[i]++;
                degree[j]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == n - 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
