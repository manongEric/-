/*************************************************************************
	> File Name: oj542_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 02:19:14 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int xy[1005][3], n, h, r, t, mark[1005], cnt, e[1005], s[1005], arr[1005][1005];
int func(int now) {
    if (e[now] == 1) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0 && arr[i][now] == 1) {
            mark[i] = 1;
            if (func(i) == 1) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    cin >> t;
    while(t--) {
        cnt = 0;
        memset(e, 0, sizeof(e));
        memset(mark, 0, sizeof(mark));
        memset(arr, 0, sizeof(arr));
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) {
            cin >> xy[i][0] >> xy[i][1] >> xy[i][2];
            if (xy[i][2] <= r) {
                s[cnt++] = i;
            }
            if (xy[i][2] + r >= h) {
                e[i] = 1;
            }
            for (int j = 1; j < i; j++) {
                int t1 = xy[i][0] - xy[j][0];
                int t2 = xy[i][1] - xy[j][1];
                int t3 = xy[i][2] - xy[j][2];
                double t4 = sqrt(t1 * t1 + t2 * t2 + t3 * t3);
                if (t4 <= 2 * r) {
                    arr[i][j] = arr[j][i] = 1;
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < cnt; i++) {
            if (mark[s[i]] == 0) {
                mark[s[i]] = 1;
                if (func(s[i]) == 1) {
                    flag = 1;
                    cout << "Yes" << endl;
                    break;
                }
            }
        }
        if (flag == 0)
        cout << "No" << endl;
    }
    return 0;
}
