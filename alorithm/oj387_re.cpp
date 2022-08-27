/*************************************************************************
	> File Name: oj387_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Mar 2022 09:42:20 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
    int id, num;
};
node wt[100005];
bool cmp (const node &a, const node &b) {
    return a.num < b.num;
}
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i].num);
        wt[i].id = i + 1;
    }
    sort(wt, wt + n, cmp);
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        int l = 0, r = n - 1;
        if (wt[r].num < t) {
            printf("%d\n", 0);
            continue;
        }
        while (l != r) {
            int mid = (l + r) / 2;
            if (wt[mid].num >= t) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        printf("%d\n", wt[l].id);
    }
    return 0;
}

