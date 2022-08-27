/*************************************************************************
	> File Name: upper.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Apr 2022 01:40:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>

int main() {
    char c;
    while (~(c = getchar())) {
        putchar(toupper(c));
    }
    return 0;
}
