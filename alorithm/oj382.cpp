/*************************************************************************
	> File Name: oj382.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Mar 2022 07:25:09 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int n, m;
int main() {
    queue<int> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    int now = 1;
    while(que.size() != 1) {
        if (now != m) {
            que.push(que.front());
            now++;
        }else {
            now = 1;
        }
        que.pop();
    }
    cout << que.front() << endl;
    return 0;
}
