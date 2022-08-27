/*************************************************************************
	> File Name: oj305_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 11:10:41 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step;
};
queue<node> que;
int n, m, sx, sy, ans;
int dir[8][2] = {0 ,1, 1, 0, 0, -1, -1, -0, 1, 1, 1, -1, -1, -1, -1, 1};
char mmap[105][105];
int main() {
    cin >> m >> n >> sx >> sy;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    que.push((node){n - sy + 1, sx, 0});
    mmap[n - sy + 1][sx] = '#';
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (mmap[xx][yy] == '.') {
                mmap[xx][yy] = '#';
                ans = temp.x + 1;
                que.push((node){xx, yy, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
