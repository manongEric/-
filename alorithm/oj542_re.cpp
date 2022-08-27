/*************************************************************************
	> File Name: oj542_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Mar 2022 02:28:21 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
long long t, n, h, r, xyz[1005][3], arr[1005][1005], cnt, mark[1005], s[1005], e[1005];
int func(int now) {
    if (e[now] == 1) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i][now] && mark[i] == 0) {
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
    while (t--) {
        cnt = 0;
        memset(arr, 0, sizeof(arr));
        memset(mark, 0, sizeof(mark));
        memset(e, 0, sizeof(e));
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) {
            cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2];
            if (xyz[i][2] <= r) {
                s[cnt++] = i;
            }
            if (xyz[i][2] + r >= h) {
                e[i] = 1;
            }
            for (int j = 1; j < i; j++) {
                int xx = xyz[i][0] - xyz[j][0];
                int yy = xyz[i][1] - xyz[j][1];
                int zz = xyz[i][2] - xyz[j][2];
                double t = sqrt(xx * xx + yy * yy + zz * zz);
                if (t <= 2 * r) {
                    arr[i][j] = arr[j][i] = 1;
                }
            }
        }
        int flag = 0;
        for (int i = 0 ; i < cnt; i++) {
            if (mark[s[i]] == 0) {
                mark[s[i]] = 1;
                if (func(s[i]) == 1) {
                    flag = 1;
                    cout << "Yes" << endl;
                    break;
                }
            }
        }
        if (flag == 0) {
            cout << "No" << endl;
        }
    }
    return 0;
}

