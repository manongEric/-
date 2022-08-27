/*************************************************************************
	> File Name: oj402_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Mar 2022 11:04:57 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node{
    int now, step;
};
int num[205], mark[205], n, a, b;
int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    queue<node> que;
    que.push((node){a, 0});
    mark[a] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.now == n) {
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
    cout << -1 << endl;
    return 0;
}

