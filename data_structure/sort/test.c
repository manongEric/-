/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Fri 29 Apr 2022 10:02:39 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a = 3, b = 4;
    a = a ^ b;
    b = b ^ a;
    a = b ^ a;
    printf("%d %d\n", a, b);
    return 0;
}
