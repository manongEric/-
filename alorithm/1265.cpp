/*************************************************************************
	> File Name: 1265.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Jan 2022 08:43:14 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

struct node {
    int e;
    double v;
    bool operator< (const node &b) const {
        return this->v > b.v;
    }
};
int n, cnt, xy[5005][2], mark[5005];
double num[5005], ans;

double func(int a, int b) {
    long long x = xy[a][0] - xy[b][0];
    long long y = xy[a][1] - xy[b][1];
    return sqrt(x * x + y * y);
}
int main() {
    //memset(num, 0x3f, sizeof(num));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        num[i] = 99999999999999;
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.e] == 1){
            continue;
        }
        ans += temp.v;
        mark[temp.e] = 1;
        cnt++;
        if (cnt == n) {
            printf("%.2f", ans);
            return 0;
        }

        for (int i = 1; i <= n; i++) {
            if (mark[i] == 0 && temp.e != i) {
                double v = func(temp.e, i);
                if (num[i] > v) {
                    num[i] = v;
                    que.push((node){i, v});
                }
            }
        }
    }


    return 0;
}

