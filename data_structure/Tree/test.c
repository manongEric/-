/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Aug 2022 04:09:41 PM CST
 ************************************************************************/

#include<stdio.h>



int main() {
    char str[100] = "abcdef";
    char *p = str;
    printf("%c\n", p[0]);
    p++;
    printf("%c\n", p[0]);
    return 0;
}
