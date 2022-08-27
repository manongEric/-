/*************************************************************************
	> File Name: oj535.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Mar 2022 07:17:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
char mmap[3005][3005]; 
int mark[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int m, n, cnt = 1, sx, sy;
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || xx > n || yy < 1 || yy > m || mark[xx][yy] == 1) continue;
        if (mmap[xx][yy] != mmap[x][y]) {
            mark[xx][yy] = 1;
            cnt++;
            func(xx, yy);
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    cin >> sx >> sy;
    mark[sx][sy] = 1;
    func(sx, sy);
    cout << cnt << endl;
    return 0;
}
