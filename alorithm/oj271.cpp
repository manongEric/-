/*************************************************************************
	> File Name: oj271.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Feb 2022 02:25:02 PM CST
 ************************************************************************/

#include<iostream>
#include<deque>
#include<cstdio>
using namespace std;

struct node{
    int x, ind;
};
int n, m, a1[300005], a2[300005], num[300005];

int main() {
    deque<node>  mmin, mmax;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        while(!mmax.empty() && mmax.back().x > num[i]) {
            mmax.pop_back();
        }
        mmax.push_back((node){num[i], i});
        if (mmax.front().ind <= i - m) {
            mmax.pop_front();
        }
        while(!mmin.empty() && mmin.back().x < num[i]) {
            mmin.pop_back();
        }
        mmin.push_back((node){num[i], i});
        if (mmin.front().ind <= i - m) {
            mmin.pop_front();
        }
        a1[i] = mmax.front().x;
        a2[i] = mmin.front().x;
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



    return 0;
}

