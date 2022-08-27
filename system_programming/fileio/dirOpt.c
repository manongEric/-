/*************************************************************************
	> File Name: dirOpt.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Apr 2022 03:44:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage : cmd + path\n");
        return 1;
    }
    DIR *dir;
    struct dirent *dp;
    if (!(dir = opendir(argv[1]))) {
        perror("opendir");
        exit(1);
    }
    while (dp = readdir(dir)) {
        printf("%s ", dp->d_name);
    }
    putchar(10);
    closedir(dir);
    return 0;
}
