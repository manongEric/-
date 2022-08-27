/*************************************************************************
	> File Name: fileopt.c
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Apr 2022 03:42:54 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage : cmd + filename\n");
        return 1;
    }

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "w");
    if (!fp1) {
        perror("open file");
        return 1;
    }
    if (!fp2) {
        perror("open file");
        return 1;
    }

    char c;
    while (~(c = fgetc(fp1))) {
        fputc(c, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
} 
