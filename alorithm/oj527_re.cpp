/*************************************************************************
	> File Name: oj527_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 11:37:36 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step, d;
};
int n, m, d, mark[105][105][105];
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main() {
    cin >> n >> m >> d;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    que.push((node){1, 1, 0, d}); 
    for (int i = 0; i <= d; i++) {
        mark[1][1][i] = 1;
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j <= d; j++) {
                int xx = temp.x + dir[i][0] * j;
                int yy = temp.y + dir[i][1] * j;
                if (xx == n && yy == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                if (mmap[xx][yy] == 0) break;
                if (mmap[xx][yy] == 'P' && mark[xx][yy][temp.d - j] == 0) {
                    mark[xx][yy][temp.d - j] = 1;
                    que.push((node){xx, yy, temp.step + 1, temp.d - j});
                }
            } 
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (xx == n && yy == m) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[xx][yy] == 'P' && mark[xx][yy][temp.d] == 0) {
                mark[xx][yy][temp.d] = 1;
                que.push((node){xx, yy, temp.step + 1, temp.d});
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}

