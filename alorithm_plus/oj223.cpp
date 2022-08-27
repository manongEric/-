/*************************************************************************
	> File Name: oj223.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Mar 2022 07:18:15 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
struct node {
    long long sum, lazy;
    int l, r, cnt;
};
node tree[40005];
int n, m, num[10005];
void up_sum(int now) {
    tree[now].sum = tree[now * 2].sum + tree[now * 2 + 1].sum;
}
void bilut_tree(int now, int l, int r) {
    tree[now].l = l; tree[now].r = r;
    tree[now].lazy = 0;
    tree[now].cnt = r - l + 1;
    if (l == r) {
        tree[now].sum = num[l];
        return;
    }
    int mid = (l + r) / 2;
    bilut_tree(now * 2, l, mid);
    bilut_tree(now * 2 + 1, mid + 1, r);
    up_sum(now);
}
void down_lazy(int now) {
    if (tree[now].lazy != 0) {
        tree[now * 2].lazy += tree[now].lazy;
        tree[now * 2 + 1].lazy += tree[now].lazy;
        tree[now * 2].sum += tree[now].lazy * tree[now * 2].cnt;
        tree[now * 2 + 1].sum += tree[now].lazy * tree[now * 2 + 1].cnt;
        tree[now].lazy = 0;
    }
}
long long  query(int now, int l, int r) {
    if (tree[now].l >= l && tree[now].r <= r) {
        return tree[now].sum;
    }
    down_lazy(now);
    long long tsum = 0;
    int mid = (tree[now].l + tree[now].r) / 2;
    if (mid >= l) tsum += query(now * 2, l, r);
    if (mid < r) tsum += query(now * 2 + 1, l, r);
    return tsum;
}
void modify(int now, int l, int r, int val) {
    if (tree[now].l >= l && tree[now].r <= r) {
        tree[now].lazy += val;
        tree[now].sum += tree[now].cnt * val;
        return;
    }
    down_lazy(now);
    int mid = (tree[now].l + tree[now].r) / 2;
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
