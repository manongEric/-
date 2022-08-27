/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 May 2022 11:03:55 AM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    int a = 321;
    char *p ;
    p = (char *)&a;
    printf("addr = %p, val = %#x\n", p, (*p));
    printf("addr = %p, val = %#x\n", p + 1, *(p + 1));
    printf("addr = %p, val = %#x\n", p + 2, *(p + 2));
    printf("addr = %p, val = %#x\n", p + 3, *(p + 3));

    printf("%#x", a);
    return 0;
}
