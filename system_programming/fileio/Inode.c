/*************************************************************************
	> File Name: Inode.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Apr 2022 01:33:45 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc, char* argv[])
{
        struct stat file_stat;
        lstat(argv[1], &file_stat);
        printf("st_dev:%lld\n", file_stat.st_dev);       //unsigned long long int
        printf("st_ino:%ld\n", file_stat.st_ino);        //unsigned long int
        printf("st_mode:%o\n", file_stat.st_mode);       //unsigned int
        printf("st_nlink:%d\n", file_stat.st_nlink);     //unsigned int
        printf("st_uid:%d\n", file_stat.st_uid);         //unsigned int
        printf("st_gid:%d\n", file_stat.st_gid);         //unsigned int
        printf("st_rdev:%lld\n", file_stat.st_rdev);     //unsigned long long int
        printf("st_size:%ld\n", file_stat.st_size);      //long int
        printf("st_blksize:%ld\n", file_stat.st_blksize);//long int
        printf("st_blocks:%ld\n", file_stat.st_blocks);  //long int
        printf("Last status change:       %s\n", ctime(&file_stat.st_ctime));// struct timespec
        printf("Last file access:         %s\n", ctime(&file_stat.st_atime));// struct timespec
        printf("Last file modification:   %s\n", ctime(&file_stat.st_mtime));// struct timespec
        return 0;

}

