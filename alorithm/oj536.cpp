/*************************************************************************
	> File Name: oj397.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Mar 2022 08:23:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
char mmap[105][105];
int n, m, cnt, ans;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '1') {
            mmap[xx][yy] = '0';
            cnt++;
            func(xx, yy);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '1') {
                mmap[i][j] = '0';
                cnt = 1;
                func(i, j);
                ans = max(cnt, ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
