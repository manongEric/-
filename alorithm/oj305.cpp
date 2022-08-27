/*************************************************************************
	> File Name: oj305.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Mar 2022 04:09:26 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step;
};
int n, m, sx, sy, ans;
int dir[8][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};
char mmap[105][105];
int main() {
    cin >> m >> n >> sx >> sy;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push((node){sx + n - 1, sy, 0});
    mmap[sx + n - 1][sy] = '#';
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = '#';
                ans = temp.step + 1;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}

