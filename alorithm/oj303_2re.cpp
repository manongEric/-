/*************************************************************************
	> File Name: oj303_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 08:46:51 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step;
};
int ans[1005][1005], n, m;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[1005][1005];
int main() {
    cin >> n >> m;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                que.push({i, j, 0});
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
            if (ans[x][y] != 0) continue;
            if (mmap[x][y] == '0') {
                ans[x][y] = temp.step + 1;
                que.push({x, y, temp.step + 1});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            if (ans[i][j] == -1) cout << "0";
            else cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
