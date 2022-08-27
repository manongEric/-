/*************************************************************************
	> File Name: 1265.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Mar 2022 04:52:06 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
struct node {
    int e;
    double v;
    bool operator <(const node &b) const{
        return this->v > b.v;
    }
};
int n, mark[5005], cnt, xy[2][5005];
double ans, num[5005];
double func(int a, int b) {
    long long x = xy[0][a] - xy[0][b];
    long long y = xy[1][a] - xy[1][b];
    return sqrt(x * x + y * y);
} 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xy[0][i] >> xy[1][i];
        num[i] = 9999999999999999;
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.e] == 1) {
            continue;
        }
        ans += temp.v;
        cnt++;
        mark[temp.e] = 1;
        if (cnt == n) {
            printf("%.2f\n", ans);
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (mark[i] == 0 && temp.e != i) {
                double v = func(i, temp.e);
                if (num[i] > v) {
                    num[i] = v;
                    que.push((node){i, v});
                }
            }
        }
    }

    return 0;
}

