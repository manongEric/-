/*************************************************************************
	> File Name: common.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Thu 17 Feb 2022 08:15:21 PM CST
 ************************************************************************/

#include "head.h"
int socket_create(int port) {
    int sockfd;
    struct sockaddr_in server;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int));

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }

    if (listen(sockfd, 20) < 0) {
        return -1;
    }
    return sockfd;
}

int socket_connect(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }

    return sockfd;
}


int make_nonblock(int fd) {
    int flags;
    if ((flags = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flags |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flags);
    
}
int make_block(int fd) {
    int flags;
    if ((flags = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flags &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flags);
    
}

char *get_conf_value(const char *file, const char *key){
    FILE *fp;
    char *line = NULL, *sub = NULL;
    ssize_t len = 0, nread = 0;
    //char ans[512] = {0};
    if ((fp = fopen(file, "r")) == NULL) {
        return NULL;
    }
    bzero(ans, sizeof(ans));

    while ((nread = getline(&line, &len, fp)) != -1) {
        if((sub = strstr(line, key)) == NULL) continue;
        if (sub == line && line[strlen(key)] == '=') {
            strcpy(ans, line + strlen(key) + 1);
            if (ans[strlen(ans) - 1] == '\n') {//line会带一个换行
                ans[strlen(ans) - 1] = '\0';
            }
        } 
    }
    fclose(fp);
    free(line);
    if (!strlen(ans)) return NULL;
    return ans;
}
