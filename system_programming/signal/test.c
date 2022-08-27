/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Apr 2022 11:33:40 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main() {
    alarm(6);
    while (1) {
        sleep(1);
        unsigned int unalarm = alarm(2);
        printf("%d\n", unalarm);
    }
    return 0;
}
