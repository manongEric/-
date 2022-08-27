/*************************************************************************
	> File Name: oj530_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Mar 2022 12:02:16 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node {
    int x, y;
};
queue<node> que; 
int n, m, q, mark[55][55], dir_cnt;
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '*') {
                mmap[i][j] = '.';
                que.push((node){i, j});
            }
        }
    }
    cin >> q;
    while (q--) {
        string s;
        int size_cnt = que.size();
        cin >> s;
        if (s == "NORTH") {
            dir_cnt = 3;
        } else if (s == "EAST") {
            dir_cnt = 0;
        } else if (s == "SOUTH") {
            dir_cnt = 1;
        } else {
            dir_cnt = 2;
        }
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i < size_cnt; i++) {
            node temp = que.front();
            que.pop();
            for (int j = 1; 1; j++) {
                int xx = temp.x + dir[dir_cnt][0] * j;
                int yy = temp.y + dir[dir_cnt][1] * j;
                if (mmap[xx][yy] != '.') break;
                if (mark[xx][yy] == 0) {
                    mark[xx][yy] = 1;
                    que.push((node){xx, yy});
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

