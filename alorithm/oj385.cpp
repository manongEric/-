/*************************************************************************
	> File Name: oj385.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Mar 2022 04:09:09 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct node {
    int time, country;
};
queue<node> que;
int num[100005], ans, n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t, p, c;
        scanf("%d%d", &t, &p);
        for (int j = 0; j < p; j++) {
            scanf("%d", &c);
            que.push((node){t, c});
            if (num[c] == 0) ans++;
            num[c]++;
        }
        while (!que.empty()) {
            node temp = que.front();
            if (t - temp.time < 86400) break;
            que.pop();
            num[temp.country]--;
            if (num[temp.country] == 0) ans--;
        }
        printf("%d\n", ans);
    }
    return 0;
}

