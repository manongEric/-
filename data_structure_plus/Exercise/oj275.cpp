/*************************************************************************
	> File Name: oj275.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 30 May 2022 03:18:57 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char str[1000005];
int P = 13331;
unsigned long long chash[1000005], p[1000005];
unsigned long long get(int l, int r) {
    return chash[r] -chash[l - 1] * p[r - l + 1];
}
int main() {
    int n;
    scanf("%s", str + 1);
    scanf("%d", &n);
    int len = strlen(str + 1);
    p[0] = 1;
    for (int i = 1; i <= len; i++) {
        p[i] = p[i - 1] * P;//存进制
        chash[i] = chash[i - 1] * P + str[i];
    }
    while (n--) {
        int l1, l2, r1, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) 
            printf("Yes\n");
        else 
            printf("No\n");
    }



    return 0;
}
