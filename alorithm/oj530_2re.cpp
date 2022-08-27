/*************************************************************************
	> File Name: oj530_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 11:26:40 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node {
    int x, y;
};
char mmap[55][55];
int n, m, q, sx, sy, dir_cnt, mark[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '*') {
                sx = i;
                sy = j;
                mmap[sx][sy] = '.';
            }
        }
    }
    queue<node> que;
    que.push({sx, sy});
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int que_size = que.size();
        if (s == "NORTH") {
            dir_cnt = 3;
        } else if (s == "WEST") {
            dir_cnt = 2;
        } else if (s == "SOUTH") {
            dir_cnt = 1;
        } else {
            dir_cnt = 0;
        }
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i < que_size; i++) {
            node temp = que.front();
            que.pop();
            for (int j = 1; 1; j++) {
                int x = temp.x + dir[dir_cnt][0] * j;
                int y = temp.y + dir[dir_cnt][1] * j;
                if (mmap[x][y] != '.') break;
                if (mark[x][y] == 0) {
                    mark[x][y] = 1;
                    que.push({x, y});
                }
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        mmap[temp.x][temp.y] = '*';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mmap[i][j];
        }
        cout << endl;
    }
    return 0;
}
