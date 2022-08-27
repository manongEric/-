/*************************************************************************
	> File Name: oj271_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 02:35:59 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int a1[300005], a2[300005], n, k;
struct node {
    int ind, val;
};
int main() {
    deque<node> mmax, mmin;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        while (!mmax.empty() && mmax.back().val > t) {
            mmax.pop_back();
        }
        mmax.push_back({i, t});
        if (mmax.front().ind == i - k) {
            mmax.pop_front();
        }
        while (!mmin.empty() && mmin.back().val < t) {
            mmin.pop_back();
        }
        mmin.push_back({i, t});
        if (mmin.front().ind == i - k) {
            mmin.pop_front();
        }
        a1[i] = mmax.front().val;
        a2[i] = mmin.front().val;
    }
    for (int i = k; i <= n; i++) {
        if (i != k) printf(" ");
        printf("%d", a1[i]);
    }
    printf("\n");
    for (int i = k; i <= n; i++) {
        if (i != k) printf(" ");
        printf("%d", a2[i]);
    }
    printf("\n");
    return 0;
}

