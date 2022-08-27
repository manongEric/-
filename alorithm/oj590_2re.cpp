/*************************************************************************
	> File Name: oj590_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 11:14:14 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int num[1005][1005], utd[1005][1005], dtu[1005][1005], sum[1005][1005],mmax2[1005], mmax_ind[1005], n, q;
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            utd[i][j] = num[i][j] + max(utd[i - 1][j], utd[i - 1][j - 1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dtu[i][j] = num[i][j] + max(dtu[i + 1][j], dtu[i + 1][j + 1]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum[i][j] = dtu[i][j] + utd[i][j] - num[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        int t = 0, t2 = 0, ind;
        for (int j = 1; j <= i; j++) {
            if (sum[i][j] > t) {
                t2 = t;
                t = sum[i][j];
                ind = j;
            } else if (t2 < sum[i][j]){
                t2 = sum[i][j];
            }
        }
        mmax2[i] = t2; mmax_ind[i] = ind;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {
            printf("%d\n", -1);
            continue;
        }
        if (mmax_ind[a] == b) {
            printf("%d\n", mmax2[a]);
        } else {
            printf("%d\n", sum[1][1]);
        }
    }
    return 0;
}
