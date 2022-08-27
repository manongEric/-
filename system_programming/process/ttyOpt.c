/*************************************************************************
	> File Name: ttyOpt.c
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Apr 2022 02:44:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    //查看终端对应的设备文件名
    printf("fd %d : %s\n", 0, ttyname(0));
    printf("fd %d : %s\n", 1, ttyname(1));
    printf("fd %d : %s\n", 2, ttyname(2));

    return 0;
}
