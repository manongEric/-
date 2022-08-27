/*************************************************************************
	> File Name: oj386.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Feb 2022 11:09:51 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
    int id, num;
};
bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}
node wt[100005];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i].num);
        wt[i].id = i + 1;
    }
    sort(wt, wt + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1, f = 0;
        scanf("%d", &t);
        while(l <= r) {
            int mid = (l + r) / 2;
            if (wt[mid].num == t) {
                f = 1;
                printf("%d\n", wt[mid].id);
                break;
            }else if (wt[mid].num < t) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        if (f == 0) {
            printf("%d\n", 0);
        }
    }
    return 0;
}

