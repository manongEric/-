/*************************************************************************
	> File Name: oj405_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 12:07:31 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
struct node {
    int x, y;
};
stack<node> sta;
char mmap[3005][3005];
int n, m, k, cnt, mark[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m || mark[xx][yy] != 0) continue;
        if (mmap[xx][yy] != mmap[x][y]) {
            cnt++;
            mark[xx][yy] = 1;
            sta.push({xx, yy});
            func(xx, yy);
        }
    }
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
                sta.push({i, j});
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
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", mark[a][b]);
    }
    return 0;
}
