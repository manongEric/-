/*************************************************************************
	> File Name: oj81.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Mar 2022 02:18:29 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node {
    int x, y, step, flag;
};
int n, m, sx, sy, mark[2005][2005];
char mmap[2005][2005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            while (scanf("%[^\n]c", &mmap[i][j])) {
                getchar();
            }
           // cin >> mmap[i][j];
            //getchar();
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
        //getchar();
    }
   /* for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", mmap[i][j]);
            }
    }*/
    queue<node> que;
    que.push((node){sx, sy, 0, 0});
    mark[sx][sy] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'T' && temp.flag == 1) {
                printf("%d\n", temp.step + 1);
                return 0;
            }
            if ((temp.flag == 0 && (mark[x][y] & 1) != 0) || (temp.flag == 1 && (mark[x][y] & 2) != 0)) {
                continue;
            }
            if (mmap[x][y] == 'S' || mmap[x][y] == '.' || mmap[x][y] == 'T') {
                mark[x][y] += temp.flag + 1;
                que.push((node){x, y, temp.step + 1, temp.flag});
            }
            if (mmap[x][y] == 'P') {
                mark[x][y] = 3;
                que.push((node){x, y, temp.step + 1, 1});
            }
        }
    }
    return 0;
}
