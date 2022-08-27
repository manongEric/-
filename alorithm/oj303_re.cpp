/*************************************************************************
	> File Name: oj303_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 10:48:26 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step;
};
queue<node> que;
int ans[1005][1005], n, m;
char mmap[1005][1005];
int dir[4][2] = {0 ,1, 1, 0, 0, -1, -1, 0};
int main (){
    cin >> n >> m;
    for (int i  = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                que.push((node){i, j, 0});
                ans[i][j] = -1;
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (xx < 1 || yy < 1 || xx > n || yy > m || ans[xx][yy] != 0) continue;
            que.push((node){xx, yy, temp.step + 1});
            ans[xx][yy] = temp.step + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            if (ans[i][j] == -1) cout << "0";
            else cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}

