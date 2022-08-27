/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 May 2022 12:37:13 PM CST
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
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#define SERV_PORT 8000
#define MAXLINE 80

void *up_server(void *arg) {
    pthread_detach(pthread_self());
    int connfd = (int)arg;
    char buf[MAXLINE];
    int n;
    while (1) {        
        n = read(connfd, buf, MAXLINE);
        if (!strncmp("quit", buf, 4))
            break;
            write(1, buf, n);
        for (int i = 0; i < n; i++) {
            buf[i] = toupper(buf[i]);
        }
        write(connfd, buf, n);
    }
    close(connfd);
    return (void *)0;
}
int main() {
    
    struct sockaddr_in severaddr, cliaddr;
    int listenfd, connfd;
    socklen_t cliaddr_len;

    //char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int n;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);


    bzero(&severaddr, sizeof(severaddr));
    severaddr.sin_family = AF_INET;
    severaddr.sin_port = htons(SERV_PORT);
    severaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listenfd, (struct sockaddr *)&severaddr, sizeof(severaddr)) < 0) {
        perror("bind");
        exit(1);
    }
    
    if (listen(listenfd, 3) < 0) {
        perror("listen");
        exit(1);
    }
    printf("Aceepting coneections...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len);
        if (connfd < 0) {
            perror("accept");
            exit(1);
        }
        printf("receved from %s : %d\n", \
              inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), 
               ntohs(cliaddr.sin_port));

        //父进程 等待 创建连接
      /*  pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        }
        if (pid > 0) {
            close(connfd);
            while (waitpid(-1, NULL, WNOHANG) > 0) {};
            continue;
        }
        
        close(listenfd);
        while (1) {
            
            n = read(connfd, buf, MAXLINE);
            if (!strncmp("quit", buf, 4))
                break;
            write(1, buf, n);
            for (int i = 0; i < n; i++) {
                buf[i] = toupper(buf[i]);
            }

            write(connfd, buf, n);
        }
        close(connfd);*/
        
        //多线程
        pthread_t tid;
        pthread_create(&tid, NULL, up_server, (void *)connfd);
        printf("new thread is %#lx\n", tid);
    }
    return 0;
}
