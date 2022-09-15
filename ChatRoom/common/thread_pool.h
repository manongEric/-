/*************************************************************************
	> File Name: thread_pool.h
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 15 Feb 2022 06:18:19 PM CST
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
struct task_queue{
    int head, tail, size, total;
    void **data;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};
void task_queue_init(struct task_queue *taskQueue, int size);
void task_queue_push(struct task_queue *taskQueue, void *data);
void *task_queue_pop(struct task_queue *taskQueue);

void *thread_run(void *arg);
void *worker(void *arg);
#endif
