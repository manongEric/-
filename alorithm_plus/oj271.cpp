/*************************************************************************
	> File Name: oj271.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Mar 2022 10:46:51 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct node {
    int val, ind;
};
int n, m, a1[300005], a2[300005];
int main() {
    scanf("%d%d", &n, &m);
    deque<node> mmax, mmin;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        while (!mmax.empty() && mmax.back().val > a) {
            mmax.pop_back();
        }
        mmax.push_back((node){a, i});
        if (mmax.front().ind == i - m) {
            mmax.pop_front();
        }
        while (!mmin.empty() && mmin.back().val < a) {
            mmin.pop_back();
        }
        mmin.push_back((node){a, i});
        if (mmin.front().ind == i - m) {
            mmin.pop_front();
        }
        a1[i] = mmax.front().val;
        a2[i] = mmin.front().val;
    }
    for (int i = m; i <= n; i++) {
        if (i != m) printf(" ");
        printf("%d", a1[i]);
    }
    printf("\n");
    for (int i = m; i <= n; i++) {
        if (i != m) printf(" ");
        printf("%d", a2[i]);
    }
    printf("\n");
    return 0;
}
