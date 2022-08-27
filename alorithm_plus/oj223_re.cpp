/*************************************************************************
	> File Name: oj223_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 10:42:47 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
struct tree {
    long long sum, lazy;
    int l, r, cnt;
};
tree node[40005];
int n, m, num[10005];
void up_sum(int now) {
    node[now].sum = node[now * 2].sum + node[now * 2 + 1].sum;
}
void down_lazy(int now) {
    if (node[now].lazy != 0) {
        node[now * 2].lazy += node[now].lazy;
        node[now * 2 + 1].lazy += node[now].lazy;
        node[now * 2].sum += node[now * 2].cnt * node[now].lazy;
        node[now * 2 + 1].sum += node[now * 2 + 1].cnt * node[now].lazy;
        node[now].lazy = 0;
    }
}
void bilut_tree(int now, int l, int r) {
    node[now].l = l; node[now].r = r;
    node[now].lazy = 0; node[now].cnt = r - l + 1;
    if (l == r) {
        node[now].sum = num[l];
        return;
    }
    int mid = (l + r) / 2;
    bilut_tree(now * 2, l, mid);
    bilut_tree(now * 2 + 1, mid + 1, r);
    up_sum(now);
}
long long query(int now, int l, int r) {
    if (node[now].l >= l && node[now].r <= r){
        return node[now].sum;
    }
    down_lazy(now);
    int mid = (node[now].l + node[now].r) / 2;
    long long tsum = 0;
    if (mid >= l) tsum += query(now * 2, l, r);
    if (mid < r) tsum += query(now * 2 + 1, l, r);
    return tsum;
}
void modify(int now, int l, int r, int val) {
    if (node[now].l >= l && node[now].r <= r) {
        node[now].lazy += val;
        node[now].sum += node[now].cnt * val;
        return;
    }  
    down_lazy(now);
    int mid = (node[now].l + node[now].r) / 2;
    if (mid >= l) modify(now * 2, l, r, val);
    if (mid < r) modify(now * 2 + 1, l, r, val);
    up_sum(now);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    bilut_tree(1, 1, n);
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            modify(1, a, b, c);
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(1, a, b));
        }
    }
    return 0;
}
