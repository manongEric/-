/*************************************************************************
	> File Name: envOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Apr 2022 04:42:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void) {
    printf("path value = [%s]\n", getenv("PATH"));
    setenv("PATH", "hell", 1);
    printf("path value = [%s]\n", getenv("PATH"));

    extern char **environ;

    for (int i = 0; environ[i]; i++) {
        printf("%s\n", environ[i]);
    }
    return 0;
}
