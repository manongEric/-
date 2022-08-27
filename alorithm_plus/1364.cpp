/*************************************************************************
	> File Name: 1364.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Mar 2022 07:55:32 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int n, num[105], arr[105][105];
int main() {
    memset(arr, 0x3f, sizeof(arr));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> num[i] >> a >> b;
        if (a != 0) arr[a][i] = arr[i][a] = 1;
        if (b != 0) arr[b][i] = arr[i][b] = 1;
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
            t += num[j] * arr[j][i];
        }
        ans = min(t, ans);
    }
    cout << ans << endl;
    return 0;
}
