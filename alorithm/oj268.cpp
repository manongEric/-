/*************************************************************************
	> File Name: oj268.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 May 2022 08:39:55 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
queue<int> que[1005];
queue<int> m_que;
unordered_map<int, int> map;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            map[a] = i;
        }
    }
    string op;
    while (cin >> op) {
        if (op == "STOP")
            break;
        if (op == "ENQUEUE") {
            int b;
            cin >> b;
            que[map[b]].push(b);
            if (que[map[b]].size() == 1) 
                m_que.push(map[b]);
        } else {
            cout << que[m_que.front()].front() << endl;
            que[m_que.front()].pop();
            if (que[m_que.front()].empty())
                m_que.pop();
        }
    }
    return 0;
}
