/*************************************************************************
	> File Name: mmap_v1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Mar 2022 10:11:51 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
char mmap[105][105];
int dir[4][2] = {0 ,1, 1, 0, 0, -1, -1, 0};
int sx, sy, n, m;
int func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == 'T') {
            return 1;
        }
        if (mmap[xx][yy] == '.') {
            mmap[xx][yy] = '0';
            int t = func(xx, yy);
            if (t == 1) {
                return 1;
            }
        }
    }
        return 0;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    int t = func(sx, sy);
    if (t == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
} 
