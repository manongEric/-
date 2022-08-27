/*************************************************************************
	> File Name: oj401.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 10:22:31 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int x, y, step;
};
queue<node> que;
int num[505][505], mark[505][505], n;
int dir[12][2] = { 2, 2, 2, -2, -2, -2, -2, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -1, 2, -2, 1};
int main() {
    cin >> n;
    que.push((node){1, 1, 0});
    mark[1][1] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (xx < 1 || yy < 1 || xx > 500 || yy > 500 || mark[xx][yy] != 0) continue;
            mark[xx][yy] = temp.step + 1;
            que.push((node){xx, yy, temp.step + 1});
        }
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1 && b == 1) cout << "0" << endl;
        cout << mark[a][b] << endl;
    }
    return 0;
}
