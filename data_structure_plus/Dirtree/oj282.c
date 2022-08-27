/*************************************************************************
	> File Name: oj282.c
	> Author: 
	> Mail: 
	> Created Time: Thu 19 May 2022 02:49:32 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 3200000
#define MAX_K 30

struct Node {
    int flag;
    int next[2];
}tree[MAX_N + 5];
int node_cnt = 1, root = 0;

int getNewNode() {return node_cnt++;}

void insert(int x) {
    int p = root;
    for (int i = MAX_K; i >= 0; i--) {
        int ind = !!(x & (1 << i));
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
        p = tree[p].next[ind];
    }
    tree[p].flag = 1;
    return ;
}

int find(int x) {
    int p = root, ans = 0;
    for (int i = MAX_K; i >= 0; i--) {
        int ind = !(x & (1 << i));
        if (tree[p].next[ind]) {
            ans |= (1 << i);
            p = tree[p].next[ind];
        } else {
            p = tree[p].next[!ind];
        }
    }
    return ans;
}
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0, val, fval = 0; i < n; i++) {
        scanf("%d", &val);
        if (i) fval = find(val);
        if (fval > ans) ans = fval;
        insert(val);
    }
    printf("%d\n", ans);

    return 0;
}
