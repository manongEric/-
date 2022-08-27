/*************************************************************************
	> File Name: oj530.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Mar 2022 06:55:52 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node {
    int x, y;
};
int n, m, k, mark[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[55][55];
int main() {
    queue<node> que;
    cin >> n >> m ;
    for (int i = 1 ;i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '*') {
                mmap[i][j] = '.';
                que.push((node){i, j});
            }
        }
    }
    cin >> k;
    while (k--) {
        string s;
        int dir_num, size_cnt = que.size();
        cin >> s;
        if (s == "EAST") {
            dir_num = 0;
        } else if (s == "SOUTH") {
           dir_num = 1; 
        } else if (s == "WEST") {
            dir_num = 2;
        } else {
            dir_num = 3;
        }
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i < size_cnt; i++) {
            node temp = que.front();
            que.pop();
            for (int j = 1; 1; j++) {
                int x = temp.x + dir[dir_num][0] * j;
                int y = temp.y + dir[dir_num][1] * j;
                if (mmap[x][y] != '.') {
                    break;
                }
                if (mark[x][y] == 0) {
                    mark[x][y] = 1;
                    que.push((node){x, y});
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
        cout << &mmap[i][1] << endl;
    }
    return 0;
}

