/*************************************************************************
	> File Name: prim.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Mar 2022 04:06:37 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
struct node {
    int e; 
    double v;
    bool operator< (const node &b) const {
        return this->v > b.v;
    }
};
int mark[5005] ,n, cnt, xy[5005][2];
double num[5005], ans;
double func(int a, int b) {
    long long t1 = (xy[a][0] - xy[b][0]);
    long long t2 = (xy[a][1] - xy[b][1]);
    return sqrt(t1 * t1 + t2 * t2);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        num[i] = 9999999999999999;
    }
    priority_queue<node> que;
    que.push((node){n, 0});
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.e] == 1) {
            continue;
        }
        mark[temp.e] = 1;
        ans += temp.v;
        cnt++;
        if (cnt == n) {
            printf("%.2lf\n", ans);
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (mark[i] == 0 && temp.e != i) {
                double v = func(i, temp.e);
                if (num[i] > v) {
                    num[i] = v;
                    que.push({i, v});
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

