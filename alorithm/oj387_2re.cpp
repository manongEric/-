/*************************************************************************
	> File Name: oj386_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 02:24:06 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node {
    int id, num;
};
bool cmp (const node &a, const node &b) {
    return a.num < b.num;
}
node wt[100005];
int n, m;
int bs(node *wt, int x) {
    int l = 0, r = n - 1;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (wt[mid].num >= x) r = mid;
        else l = mid + 1;
    }
    return wt[l].id;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> wt[i].num;
        wt[i].id = i + 1;
    }
    sort(wt, wt + n, cmp);
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        if (a > wt[n - 1].num) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", bs(wt, a));
        }
    }
    return 0;
}
