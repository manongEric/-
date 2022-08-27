/*************************************************************************
	> File Name: Dictree_arr.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 May 2022 06:29:12 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
#define num 26
struct node {
    int cnt;
    int next[num];
}tree[MAX_N + 5];
int root = 0, newNode = 1;

int getNode() {return newNode++;}
void insert(const char *s) {
    int p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].cnt += 1;
}

int find(const char *s) {
    int p = root;
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        p = tree[p].next[s[i] - 'a'];
        if (p == 0) return ans;
        ans += tree[p].cnt;
    }
    return ans;
}

char str[MAX_N + 5];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(str);
    }
    for (int i = 0 ;i < m; i++) {
        scanf("%s", str);
        printf("%d\n", find(str));
    }
    
    return 0;
}
