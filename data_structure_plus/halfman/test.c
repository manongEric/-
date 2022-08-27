/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Sun 29 May 2022 03:54:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    //char buff[] = {'1', '2', '3', '0', '4'};
    char buff[6];
    buff[0] = 'a';
    buff[1] = 'b';
    buff[2] = 'c';
    buff[3] = 'd';
    char *str;
    str = strdup(buff);
    printf("%c\n", buff[4]);
    printf("%s\n", str);

    return 0;
}
