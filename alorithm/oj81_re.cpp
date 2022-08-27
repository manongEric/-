/*************************************************************************
	> File Name: oj81_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Mar 2022 08:46:22 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct node {
    int x, y, step, flag;
};
queue<node> que;
char mmap[2005][2005];
int n, m, sx, sy, dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0,}, mark[2005][2005];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &mmap[i][j]);
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    que.push((node){sx, sy, 0, 0});
    mark[sx][sy] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (temp.flag == 1 && mmap[xx][yy] == 'T') {
                printf("%d\n", temp.step + 1);
                //cout << xx << " " << yy << "end" << endl;
                return 0;
            }
            if (temp.flag == 0 && (mark[xx][yy] & 1) != 0 || temp.flag == 1 && (mark[xx][yy] & 2) != 0) {
                continue;
            }
            if (mmap[xx][yy] == '.' || mmap[xx][yy] == 'T' || mmap[xx][yy] == 'S') {
                mark[xx][yy] += temp.flag + 1;
               // cout << xx << " " << yy << "path" << endl;
                que.push((node){xx, yy, temp.step + 1, temp.flag});
            }
            if (mmap[xx][yy] == 'P') {
                mark[xx][yy] == 3;
                que.push((node){xx, yy, temp.step + 1, 1});
            }
        }
    }
    return 0;
}
