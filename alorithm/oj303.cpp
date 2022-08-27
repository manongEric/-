/*************************************************************************
	> File Name: oj303.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Mar 2022 03:38:26 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step;
};
char mmap[1005][1005];
int ans[1005][1005];
int n, m;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, -0};
int main() {
    cin >> n >> m;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                que.push((node){i, j, 0});
                ans[i][j] = -1;
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || x > n || y < 1 || y > m || ans[x][y] != 0) continue;
            else {
                ans[x][y] = temp.step + 1;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            if (ans[i][j] == -1) {
                cout << 0;
            } else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}

