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
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

void printDir(char *dirname) {
    char pathname[1024];
    DIR *dir;
    struct dirent *dp;
    struct stat st;
    if (!(dir = opendir(dirname))) {
        perror("opendir");
        exit(1);
    }
    while (dp = readdir(dir)) {
        if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) 
            continue;
        sprintf(pathname, "%s/%s", dirname, dp->d_name);
        if (stat(pathname, &st) < 0) {
            perror("stat");
            exit(1);
        }
        if (S_ISDIR(st.st_mode)) {
            printDir(pathname);
        }
        printf("%s ", dp->d_name);
    }
    putchar(10);
    closedir(dir);
}
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage : cmd + path\n");
        return 1;
    }
    printDir(argv[1]);
    return 0;
}
