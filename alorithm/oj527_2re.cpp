/*************************************************************************
	> File Name: oj527_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 09:27:37 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step, d;
};
char mmap[105][105];
int mark[105][105][105], dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m, d;
int main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push({1, 1, 0, d});
    for (int i = 0; i <= d; i++) {
        mark[1][1][i] = 1;
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j <= temp.d; j++) {
                int x = temp.x + j * dir[i][0];
                int y = temp.y + j * dir[i][1];
                if (mmap[x][y] == 0) break;
                if (x == n && y == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                if (mmap[x][y] == 'P' && mark[x][y][temp.d - j] == 0) {
                    mark[x][y][temp.d - j] = 1;
                    que.push({x, y, temp.step + 1, temp.d - j});
                }
            }
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == n && y == m) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == 'P' && mark[x][y][temp.d] == 0) {
                mark[x][y][temp.d] = 1;
                que.push({x, y, temp.step + 1, temp.d});
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
