/*************************************************************************
	> File Name: oj383.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Apr 2022 10:58:18 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int x, y, n;
int main() {
    cin >> x >> y >> n;
    queue<int> b, g;
    for (int i = 1; i <= x; i++) {
        b.push(i);
    }
    for (int j = 1; j <= y; j++) {
        g.push(j);
    }
    while(n--) {
        int t1 = b.front();
        int t2 = g.front();
        b.push(t1);
        g.push(t2);
        b.pop();
        g.pop();
        cout << t1 << " " << t2 << endl;
    }
    return 0;
}
