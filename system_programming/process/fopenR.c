/*************************************************************************
	> File Name: fopenR.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Apr 2022 09:38:48 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main() {
    FILE *fp = popen("cat ./hello.txt", "r");

    if (!fp){
        perror("popen");
        exit(1);
    }

    int c;
    while(~(c = fgetc(fp)))
        putchar(toupper(c));

    pclose(fp);


    return 0;
}
