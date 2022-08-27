/*************************************************************************
	> File Name: 1119.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Mar 2022 08:29:40 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int n, m, q, num[205], arr[205][205];
int main() {
    memset(arr, 0x3f, sizeof(arr));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++; b++;
        arr[a][b] = arr[b][a] = c;
    }
    int now = 1;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a++; b++;
        while (now <= n && num[now] <= c) {
            for (int j = 1; j <= n; j++) {//即使两个点修好了也只能先1后2慢慢利用floyd
                for (int k = 1; k <= n; k++) {
                    arr[j][k] = min(arr[j][k], arr[j][now] + arr[now][k]);
                }
            }
            now++;
        }
        if (num[a] > c || num[b] > c || arr[a][b] == 0x3f3f3f3f) {
            cout << -1 << endl;
        } else {
            cout << arr[a][b] << endl;
        } 
    }

    return 0;
}
