/*************************************************************************
	> File Name: 1119.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Jan 2022 10:18:24 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int arr[205][205], num[205], n, m, q;

int main() {
    memset(arr, 0x3f, sizeof(arr));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        arr[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++; b++;
        arr[a][b] = arr[b][a] = c;
    }

    int now = 1;
    cin >> q;
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a++; b++;
        while(now <= n && num[now] <= c) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <=n; k++) {
                    arr[j][k] = min(arr[j][k], arr[j][now] + arr[now][k]);
                }
            }
            now++;
        }
        if (num[a] > c || num[b] > c || arr[a][b] == 0x3f3f3f3f) {
            cout << -1 << endl;
        }
        else {
            cout << arr[a][b] << endl;
        }
    }
    return 0;
}
