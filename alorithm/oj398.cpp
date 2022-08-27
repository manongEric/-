/*************************************************************************
	> File Name: oj398.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Mar 2022 01:43:43 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step;
};
int mmap[405][405], n, m, sx, sy;
int dir[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2};
int main() {
    cin >> n >> m >> sx >> sy;
    queue<node> que;
    que.push((node){sx, sy, 0});
    mmap[sx][sy] = -1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || x > n || y < 1 || y > m || mmap[x][y] != 0) continue;
            else {
                mmap[x][y] = temp.step + 1;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            if (mmap[i][j] == -1) {
                cout << 0;
            } else if (mmap[i][j] == 0) {
                cout << -1;
            } else cout << mmap[i][j];
        }
        cout << endl;
    }
    return 0;
}
