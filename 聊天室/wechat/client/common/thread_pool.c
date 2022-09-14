/*************************************************************************
	> File Name: thread_pool.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 15 Feb 2022 06:18:22 PM CST
 ************************************************************************/

#include "head.h"
extern int epollfd;
extern char *data[2000];
extern pthread_mutex_t mutex[2000];
void task_queue_init(struct task_queue *taskQueue, int size) {
    taskQueue->size = size;
    taskQueue->total = taskQueue->head = taskQueue->tail = 0;
    taskQueue->data = calloc(size, sizeof(void *));
    pthread_mutex_init(&taskQueue->mutex, NULL);
    pthread_cond_init(&taskQueue->cond, NULL);
    return ;
}

void task_queue_push(struct task_queue *taskQueue, void *data) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue->total == taskQueue->size) {
        DBG(YELLOW"<push> : taskQueue is full\n"NONE);
        DBG2(YELLOW"<push> : taskQueue is full\n"NONE);
        pthread_mutex_unlock(&taskQueue->mutex);
        return;
    }
    taskQueue->data[taskQueue->tail] = data;
    DBG(GREEN"<push> : "RED"data"NONE"is pushed!\n");
    taskQueue->tail++;
    taskQueue->total++;
    if (taskQueue->tail == taskQueue->size) {
        DBG(YELLOW"<push> taskQueue reach tail!\n"NONE);
        taskQueue->tail = 0;
    }
    pthread_cond_signal(&taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
    return ;
}

void *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    while (taskQueue->total == 0) {
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
    void *data  = taskQueue->data[taskQueue->head];
    DBG(GREEN"<pop> : "BLUE" data "NONE"is poped!\n");
    taskQueue->total--;
    taskQueue->head++;
    if (taskQueue->head == taskQueue->size) {
        DBG(YELLOW"<pop> taskQueue reach tail!\n"NONE);
        taskQueue->head = 0;
    }
    pthread_mutex_unlock(&taskQueue->mutex);
    return data;
}

void *thread_run(void *arg) {
    pthread_detach(pthread_self());
    struct task_queue *taskQueue = (struct task_queue *)arg; 
    while (1) {
        void *data = task_queue_pop(taskQueue);
        printf("%s", (char *)data);
    }
}

void do_work(int fd) {
    pthread_mutex_lock(&mutex[fd]);
    char buff[8192] = {0};
    DBG(BLUE"<R> data is ready on %d.\n"NONE, fd);
    int ind = strlen(data[fd]);
    DBG(BLUE"<R> data is ready on %d.\n"NONE, fd);
    int rsize = 0;
    if ((rsize = recv(fd, buff, sizeof(buff), 0)) < 0) {
        if (errno != EAGAIN) {
            epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
            DBG(RED"<C> : %d is closed!.\n"NONE, fd);
            close(fd);
        }
        pthread_mutex_unlock(&mutex[fd]);
        return;
    }
    for (int i = 0; i < rsize; i++) {
        if (buff[i] >= 'A' && buff[i] <= 'Z') {
            data[fd][ind++] = buff[i] + 32;
        }else if (buff[i] >= 'a' && buff[i] <= 'z') {
            data[fd][ind++] = buff[i] - 32;
        } else {
            data[fd][ind++] = buff[i];
            if (buff[i] == '\n') {
                DBG2(GREEN"<END> : \\n recved!.\n"NONE);
                send(fd, data[fd], strlen(data[fd]), 0);
            }
        }
    }
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events  = EPOLLIN | EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    pthread_mutex_unlock(&mutex[fd]);
}

void *worker(void *arg) {
    pthread_detach(pthread_self());
    struct task_queue *taskQueue = (struct task_queue *)arg; 
    while (1) {
        int *fd = (int *)task_queue_pop(taskQueue);
        do_work(*fd);
    }
}
