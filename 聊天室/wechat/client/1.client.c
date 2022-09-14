/*************************************************************************
	> File Name: 1.client.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 01 Mar 2022 07:50:47 PM CST
 ************************************************************************/

#include "head.h"

const char *config = "./wechat.conf";

int main(int argc, char **argv) {
    int opt, server_port = 0, sex = -1, sockfd, mode = 0;
    char server_ip[20] = {0}, name[50] = {0};
    while ((opt = getopt(argc, argv, "p:h:s:n:m:")) != -1) {
        switch (opt) {
            case 'p':
                server_port = atoi(optarg);
                break;
            case 's':
                sex = atoi(optarg);
                break;
            case 'm':
                mode = atoi(optarg);
                break;
            case 'h':
                strcpy(server_ip, optarg);
                break;
            case 'n':
                strcpy(name, optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -p port -n name -s sex -h server_ip.\n", argv[0]);
                exit(1);
        }
    }

    if (access(config, R_OK)) {
        fprintf(stderr, RED"<Error>"NONE" : config file error!\n");
        exit(1);
    }

    if (!server_port) server_port = atoi(get_conf_value(config, "SERVER_PORT"));
    if (sex < 0) sex  = atoi(get_conf_value(config, "SEX"));
    if (!strlen(name)) strcpy(name, get_conf_value(config, "NAME"));
    if (!strlen(server_ip)) strcpy(server_ip, get_conf_value(config, "SERVER_IP"));
    DBG(YELLOW"<D>"NONE" : read config success.\n");

    DBG2(BLUE"<D>"NONE" : server_ip = %s\n", server_ip);
    DBG2(BLUE"<D>"NONE" : server_port = %d\n", server_port);
    if ((sockfd = socket_connect(server_ip, server_port)) < 0) {
        perror("socket_connect");
        exit(1);
    }
    DBG(YELLOW"<D>"NONE" : connecttion to server %s:%d --> <%d> successfully.\n", server_ip, server_port, sockfd);
    struct wechat_msg msg;
    bzero(&msg, sizeof(msg));
    strcpy(msg.from, name);
    msg.sex = sex;
    if (mode == 0) {
        //signup
        msg.type = WECHAT_SIGNUP;
    } else {
        //signin
        msg.type = WECHAT_SIGNIN;
    }
    send(sockfd, (void *)&msg, sizeof(msg), 0);

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    if (select(sockfd + 1, &rfds, NULL, NULL, &tv) <= 0) {
        fprintf(stderr, RED"<SystemErr>"NONE" : server is out of service,\n");
        exit(1);
    }

    bzero(&msg, sizeof(msg));
    int ret = recv(sockfd, (void *)&msg, sizeof(msg), 0);
    if (ret <= 0) {
        fprintf(stderr, RED"<SystemErr>"NONE" : Server closed connecttion.\n");
        exit(1);
    }
    if (msg.type & WECHAT_ACK) {
        DBG(GREEN"<Success>"NONE" : server return a success.\n");
        if (!mode) {
            printf(GREEN"Please login after this.\n"NONE);
            exit(0);
        }
    } else {
        DBG(RED"<Failure>"NONE" : server return a failure.\n");
        exit(1);
    }

    DBG2(BLUE"<D>"NONE" : login success!\n");

    pthread_t tid;
    pthread_create(&tid, NULL, client_recv, (void *)&sockfd);

    while (1) {
        printf("Please Input:\n");
        char buff[1024] = {0};
        scanf("%[^\n]", buff);
        getchar();
        if (!strlen(buff)) continue;
        msg.type = WECHAT_WALL;
        strcpy(msg.msg, buff);
        send(sockfd, (void *)&msg, sizeof(msg), 0);
    }
    return 0;
}
