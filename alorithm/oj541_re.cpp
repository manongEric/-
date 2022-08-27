/*************************************************************************
	> File Name: oj541_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Mar 2022 12:44:12 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int n, m, arr[2][20][20], ans[2][20005], cnt[2];
void func(int person, int now, int cost) {
    if (now == n) {
        ans[person][cnt[person]] = cost;
        cnt[person]++;
        return;
    }
    for (int i = now + 1; i <= n; i++) {
        if (arr[person][now][i] != 0) {
            func(person, i, cost + arr[person][now][i]);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[0][a][b] = arr[0][b][a] = c;
        arr[1][a][b] = arr[1][b][a] = d;
    }
    func(0, 1, 0);
    func(1, 1, 0);
    sort(ans[0], ans[0] + cnt[0]);
    sort(ans[1], ans[1] + cnt[1]);
    for (int i = 0; i < cnt[0]; i++) {
        for (int j = 0; j < cnt[1]; j++) {
            if (ans[0][i] = ans[1][j]) {
                cout << ans[0][i] << endl;
                return 0;
            }
        }
    }

    return 0;
}
