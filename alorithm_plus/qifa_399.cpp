/*************************************************************************
	> File Name: qifa_399.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Mar 2022 04:56:20 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
struct node {
    int x, y, step;
    double dis;
    bool operator< (const node &b) const {
        return this->step + this->dis > b.step + b.dis;
    }
};
priority_queue<node> que;
int n, m, sx, sy, ex, ey;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[505][505];
double func(int x, int y) {
    int t1 = x - ex;
    int t2 = y - ey;
    return sqrt(t1 * t1 + t2 * t2);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j  = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '2') {
                sx = i; sy = j;
            }
            if (mmap[i][j] == '3') {
                ex = i, ey = j;
            }
        }
    }
    que.push((node){sx, sy, 0, func(sx, sy)});
    mmap[sx][sy] = '#';
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (mmap[xx][yy] == '3') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[xx][yy] == '.') {
                mmap[xx][yy] = '#';
                que.push((node){xx, yy, temp.step + 1, func(xx, yy)});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
