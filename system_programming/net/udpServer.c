/*************************************************************************
	> File Name: udpServer.c
	> Author: 
	> Mail: 
	> Created Time: Tue 10 May 2022 09:36:01 AM CST
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
    int sockfd;
    struct sockaddr_in seraddr, cliaddr;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    socklen_t cliaddr_len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    seraddr.sin_port = htons(SERVER_PORT);

    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    printf("udpserver ready~\n");
    int n;
    while (1) {
        n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *)&cliaddr, &cliaddr_len);
        if (n < 0)
            pexit("recvfrom");

        printf("received from %s : %d\n", 
              inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), 
              ntohs(cliaddr.sin_port));

        for (int i = 0; i < n; i++) {
            buf[i] = toupper(buf[i]);
        }

        sendto(sockfd, buf, n, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    }
    close(sockfd);

    return 0;
}
