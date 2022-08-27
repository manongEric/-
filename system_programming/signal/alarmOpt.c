/*************************************************************************
	> File Name: alarmOpt.c
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Apr 2022 02:31:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    alarm(5);
    sleep(3);
    unsigned int left = alarm(5);
    printf("left = %d\n", left);

    while (1) {
        printf("1 sec again\n");
        sleep(1);
    }
    return 0;
}
