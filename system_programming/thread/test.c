/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Tue 31 May 2022 12:01:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(0));
    int a = rand() % 10;
    int n = 5;
    while (n--) {
        printf("%d\n", a);
    }
    return 0;
}
