/*************************************************************************
	> File Name: udpClient.c
	> Author: 
	> Mail: 
	> Created Time: Tue 10 May 2022 09:46:38 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<strings.h>
#include<unistd.h>
#include<ctype.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>

#define SERVER_PORT 8000
#define MAXLINE 80

#define pexit(msg) {\
    perror(msg);\
    exit(1);\
}

int main() {
    struct sockaddr_in seraddr;
    int sockfd, n;
    char buf[MAXLINE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &seraddr.sin_addr);

    while (n = read(0, buf, MAXLINE)) {
        n = sendto(sockfd, buf, n, 0, (struct sockaddr*)&seraddr, sizeof(seraddr));

        n = recvfrom(sockfd, buf, MAXLINE, 0, NULL, 0);
        write(1, buf, n);
    }
    close(sockfd);
    return 0;
}
