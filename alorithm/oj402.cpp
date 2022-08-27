/*************************************************************************
	> File Name: oj402.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Mar 2022 04:44:19 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int now, step;
};
int n, a, b, num[205], mark[205];
int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++){
        cin >> num[i];
    }
    queue<node> que;
    que.push((node){a, 0});
    mark[a] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.now == b) {
            cout << temp.step << endl;
            return 0;
        }
        int up = temp.now + num[temp.now];
        int down = temp.now - num[temp.now];
        if (up <= n && mark[up] == 0) {
            mark[up] = 1;
            que.push((node){up, temp.step + 1});
        }
        if (down >= 1 && mark[down] == 0) {
            mark[down] = 1;
            que.push((node){down, temp.step + 1});
        }
    }
    cout << - 1<< endl;
    return 0;
}
