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
#include<sys/epoll.h>
#define SERV_PORT 8000
#define MAXLINE 80

typedef struct Task{
    int fd;
    struct Task *next;
}Task;

typedef struct Task_pool {
    Task *head;
    Task *tail;
    pthread_mutex_t lock;
    pthread_cond_t havetask;
}Task_pool;

Task_pool *Task_pool_init() {
    Task_pool *tp = (Task_pool*)malloc(sizeof(Task_pool));
    tp->head = tp->tail = NULL;
    pthread_mutex_init(&tp->lock, NULL);
    pthread_cond_init(&tp->havetask, NULL);
    return tp;
}


void Task_pool_push(Task_pool *tp, int fd) {
    pthread_mutex_lock(&tp->lock);

    Task *t = (Task *)malloc(sizeof(Task));
    t->fd = fd;
    t->next = NULL;

    if (!tp->tail) {
        tp->head = tp->tail = t;
    } else {
        tp->tail->next = t;
        tp->tail = t;
    }
    
    pthread_cond_broadcast(&tp->havetask);
    pthread_mutex_unlock(&tp->lock);
}

Task Task_pool_pop(Task_pool *tp) {
    pthread_mutex_lock(&tp->lock);

    while (tp->head == NULL) 
        pthread_cond_wait(&tp->havetask, &tp->lock);

    Task temp, *k;
    k = tp->head;
    temp = *k;
    tp->head = k->next;

    if (!tp->head)
        tp->tail = NULL;

    free(k);
    pthread_mutex_unlock(&tp->lock);
    return temp;
    
}

void Task_pool_free(Task_pool *tp) {
    pthread_mutex_lock(&tp->lock);
    Task *p = tp->head, *k;

    while(p) {
        k = p;
        p = p->next;
        free(k);
    }
    pthread_mutex_unlock(&tp->lock);
    free(tp);

    return;
}
void *up_server(void *arg) {
    pthread_detach(pthread_self());
    char buf[MAXLINE];
    int n;
    Task_pool *tp = arg;
    while (1) {
        Task temp = Task_pool_pop(tp);
        int connfd = temp.fd;
        printf("get task fd %d\n", connfd);
        if (1) {        
            n = read(connfd, buf, MAXLINE);
            write(1, buf, n);
            for (int i = 0; i < n; i++) {
                buf[i] = toupper(buf[i]);
            }
            write(connfd, buf, n);
        }
        printf("bye task fd %d\n", connfd);
        if (!strncmp("QUIT", buf, 4))
            close(connfd);
    }
    return (void *)0;
}
int main() {
    
    struct sockaddr_in severaddr, cliaddr;
    int listenfd, connfd;
    socklen_t cliaddr_len;

    //char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int n;

    Task_pool *tp = Task_pool_init();

    pthread_t tid;
    for (int i = 0; i < 4; i++) {
        pthread_create(&tid, NULL, up_server,(void *)tp);
        printf("new thread is %#lx\n", tid);
    }
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(1);
    }
    
    int epfd = epoll_create(256);
    struct epoll_event ev, events[256];
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = listenfd;
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

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
        int nfds = epoll_wait(epfd, events, 256, -1);
        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == listenfd) {
                cliaddr_len = sizeof(cliaddr);
                connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len);
                if (connfd < 0) {
                    perror("accept");
                    exit(1);
                }
                printf("receved from %s : %d\n", \
                inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), 
                ntohs(cliaddr.sin_port));

                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = connfd;
                epoll_ctl(epfd, EPOLL_CTL_ADD,connfd, &ev);
            } else if (events[i].events & EPOLLIN) {
                int chifd = events[i].data.fd;
                if (chifd < 3) 
                    continue;

                Task_pool_push(tp, chifd);
            }
        }
    }
    Task_pool_free(tp);
    return 0;
}
