/*************************************************************************
	> File Name: oj535.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Mar 2022 07:17:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int m, n, cnt = 1, sx, sy;
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '.') {
            mmap[xx][yy] = '#';
            cnt++;
            func(xx, yy);
        }
    }
    return;
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') {
                sx = i, sy = j;
            }
        }
    }
    func(sx, sy);
    cout << cnt << endl;
    return 0;
}
