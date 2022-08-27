/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Sun 01 May 2022 07:29:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char input[16]="abc,d";
    char*p;
    /*strtok places a NULL terminator
    infront of the token,if found*/
    p=strtok(input,",");
    if(p)
        printf("%s\n",p);
        /*Asecond call to strtok using a NULL
        as the first parameter returns a pointer
        to the character following the token*/
    p=strtok(NULL,",");
    if(p)
        printf("%s\n",p);
    return 0;
}
