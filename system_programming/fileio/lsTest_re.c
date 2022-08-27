/*************************************************************************
	> File Name: lsTest.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Apr 2022 12:54:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>
#include<pwd.h>
#include<string.h>
#include<grp.h>
#include<math.h>
double n, ans = 0;
struct stat sb;
void getAll(char *filename){
    switch(sb.st_mode & S_IFMT) {
        case S_IFREG :
            printf("-");
            break;
        case S_IFDIR :
            printf("d");
            break;
        case S_IFCHR :
            printf("c");
            break;
        default :
            printf("1");
        
    } 
    if (sb.st_mode & S_IRUSR) printf("r"); else printf("-");
    if (sb.st_mode & S_IWUSR) printf("w"); else printf("-");
    if (sb.st_mode & S_IXUSR) printf("x"); else printf("-");

    if (sb.st_mode & S_IRGRP) printf("r"); else printf("-");
    if (sb.st_mode & S_IWGRP) printf("w"); else printf("-");
    if (sb.st_mode & S_IXGRP) printf("x"); else printf("-");
    
    if (sb.st_mode & S_IROTH) printf("r"); else printf("-");
    if (sb.st_mode & S_IWOTH) printf("w"); else printf("-");
    if (sb.st_mode & S_IXOTH) printf("x"); else printf("-");
    printf(" ");

    printf("%ld ", sb.st_nlink);

    struct passwd *usrInfo;
    usrInfo = getpwuid(sb.st_uid);
    struct group *groupInfo;
    groupInfo = getgrgid(sb.st_gid);
    printf("%s ", usrInfo->pw_name);
    printf("%s ", groupInfo->gr_name);

    printf("%lld ", (long long)sb.st_size);
    
    char buf[100];
    char *p = NULL;
    strcpy(buf, ctime(&sb.st_mtime));
    p = strchr(buf, '\n');
    *p = '\0';
    printf("%s ", buf);


    printf("%s", filename);
    putchar(10);
    return;

}
void printDir(char *dirname) {
    char pathname[1024];
    DIR *dir;
    struct dirent *dp;
    if (!(dir = opendir(dirname))) {
        perror("opendir");
        exit(1);
    }
    while (dp = readdir(dir)) {
       /* if (!strcmp(dp->d_name, ".") || ! strcmp(dp->d_name, "..")){
            continue;
        }*/
        sprintf(pathname, "%s/%s", dirname, dp->d_name);
        if (lstat(pathname, &sb) < 0) {
           perror("stat");
           exit(1);
        }
        long Iosize = sb.st_blksize;
        ans += ceil(sb.st_size / 4096);
        printf("%d ", ans);
       /* if (S_ISDIR(sb.st_mode)) {
            printDir(pathname);
        }*/
        getAll(pathname);
    }
    putchar(10);
    closedir(dir);
}
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage : cmd + path");
        exit(1);
    }
    if (lstat(argv[1], &sb) < 0) {
        perror("stat");
        exit(1);
    }
    if (S_ISDIR(sb.st_mode)) {
        printDir(argv[1]);
        printf("totol : %d\n",(int)ans * 4);
    } else {
        getAll(argv[1]);
    }
    return 0;
}
