/*************************************************************************
	> File Name: 1364_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 31 Mar 2022 12:11:00 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int arr[105][105], num[105], n;
int main() {
    memset(arr, 0x3f, sizeof(arr));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int b, c;
        cin >> num[i] >> b >> c;
        if (b != 0) arr[i][b] = arr[b][i] = 1;
        if (c != 0) arr[i][c] = arr[c][i] = 1;
        arr[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    int ans = 2100000000;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 1; j <= n; j++) {
            t += num[j] * arr[i][j];
        }
        ans = min(t, ans);
    }
    cout << ans << endl;

    return 0;
}
