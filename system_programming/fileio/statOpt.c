/*************************************************************************
	> File Name: statOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Apr 2022 07:35:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

    struct stat st;
    if(argc < 2) {
        printf("usage : cmd + filename/dirnane\n");
        exit(1);
    } 
    lstat(argv[1], &st);
  // printf("st_ mode %d  s_ ifmt %d\n", st.st_mode, S_IFMT);
    switch(st.st_mode & S_IFMT) {
        case S_IFREG :
            printf("regular file\n");
            break;
        case S_IFDIR :
            printf("regular file\n");
            break;
        case S_IFCHR :
            printf("regular file\n");
            break;
        default :
            printf("other file type\n");
        
    }
    return 0;
}
