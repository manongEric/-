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
int mmap[505][505],mark[505][505], n, m, sx, sy;
int dir[12][2] = {1, 2, 2, 2, 2, 1, 2, -1, 2, -2, 1, -2, -1, -2, -2, -2,  -2, -1, -2, 1, -2, 1,-1, 2};
int main() {
    queue<node> que;
    que.push((node){1, 1, 0});
    mark[1][1] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || x > 500 || y < 1 || y > 500 || mark[x][y] == 1) continue;
            else {
                mmap[x][y] = temp.step + 1;
                mark[x][y] = 1;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sx >> sy;
        cout << mmap[sx][sy] << endl;
    }

    return 0;
}
