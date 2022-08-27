/*************************************************************************
	> File Name: 1119_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2022 11:24:43 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int arr[205][205], num[205], n, m, q;
int main() {
    cin >> n >> m;
    memset(arr, 0x3f, sizeof(arr));
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++; b++;
        arr[a][b] = arr[b][a] = c;
    }
    cin >> q;
    int now = 1;//修好的点
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a++; b++;
        while (now <= n && num[now] <= c) {
            for (int j = 1; j <= n; j++) {
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
