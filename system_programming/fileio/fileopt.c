/*************************************************************************
	> File Name: fileopt.c
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Apr 2022 03:42:54 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r+");
    if (!fp) {
        perror("open file");
        return 1;
    }
    
    fseek(fp, 0, SEEK_END);
    int b = ftell(fp);
    printf("%d\n", b);
    fclose(fp);
    return 0;
} 
