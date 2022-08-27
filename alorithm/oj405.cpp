/*************************************************************************
	> File Name: oj535.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Mar 2022 07:17:13 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
struct node{
    int x, y;
};
stack<node> sta;
char mmap[3005][3005]; 
int mark[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int m, n, k, cnt = 1;
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || xx > n || yy < 1 || yy > m || mark[xx][yy] == 1) continue;
        if (mmap[xx][yy] != mmap[x][y]) {
            mark[xx][yy] = 1;
            cnt++;
            sta.push((node){xx, yy});
            func(xx, yy);
        }
    }
    return;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mark[i][j] == 0) {
                cnt = 1;
                mark[i][j] = 1;
                sta.push((node){i, j});
                func(i, j);
                while (!sta.empty()) {
                    node temp = sta.top();
                    sta.pop();
                    mark[temp.x][temp.y] = cnt;
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int sx, sy;
        scanf("%d%d", &sx, &sy);
        printf("%d\n", mark[sx][sy]);
    }
    return 0;
}
