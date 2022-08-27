/*************************************************************************
	> File Name: mmapOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Apr 2022 02:42:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>

int main() {
    int fd = open("kaikeba.txt", O_RDWR);
    if (fd < 0) {
        perror("openen file");
        exit(1);
    }
    
    int *p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
   // char *p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
   // p[0] = 'A';
   // p[1] = 'A';
   // p[2] = 97;
    ((int *)(((char *)p + 1)))[0] = 0x30313233;
    munmap(p, 6);

    return 0;
}
