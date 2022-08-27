/*************************************************************************
	> File Name: oj397.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Mar 2022 08:23:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int mmap[105][105], n, m, cnt;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] != 0) {
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] != 0) {
                mmap[i][j] = 0;
                cnt++;
                func(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
