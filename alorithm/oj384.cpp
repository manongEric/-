/*************************************************************************
	> File Name: oj384.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Mar 2022 03:25:34 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int n, x, t;
queue<int> que;
int func(int x) {
    if (x % 7 == 0) return 0;
    while(x) {
        if (x % 10 == 7) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}
int main() {
    cin >> n >> x >> t;
    for (int i = 1; i <= n; i++) {
        if (i >= x) {
            que.push(i);
        }
    }
    for (int i = 1; i < x; i++) {
        que.push(i);
    }
    while (que.size() != 1) {
        if (func(t)) {
            que.push(que.front());
        }
        t++;
        que.pop();
    }
    cout << que.front() << endl;
    return 0;
}

