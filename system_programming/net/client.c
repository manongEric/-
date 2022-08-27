/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 May 2022 02:13:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<strings.h>
#include<unistd.h>
#include<ctype.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#define SERV_PORT 8000
#define MAXLINE 80

int main() {
    struct sockaddr_in serveraddr;
    char buf[MAXLINE];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        exit(1);
    }
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }
    int n;
    while (n = read(0, buf, MAXLINE)) {
        write(sockfd, buf, n);
        if (!strncmp("quit", buf, 4))
            break;
        n = read(sockfd, buf, MAXLINE);
        printf("response from, 陈瀚:\n");
        write(1, buf, n);
    }
    close(sockfd);
    return 0;
}
