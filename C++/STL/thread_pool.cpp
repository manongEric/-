/*************************************************************************
	> File Name: thread_pool.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Jul 2022 09:23:08 PM CST
 ************************************************************************/

#include<condition_variable>
#include<iostream>
#include<thread>
#include<queue>
#include<vector>
#include<functional>
using namespace std;


class ThreadTask{
private:
    function<void()> _fun;
public:
    template<class Ptr, class...ARGS>
    ThreadTask(Ptr ptr, ARGS ...args){
        _fun = bind(ptr, forward<ARGS>(args)...);
    }
    
    void runTask(){
        _fun();
    }
};

class ThreadPool{
private:
    int _max;
    queue<ThreadTask*> _tasks;
    vector<thread*> _threads;
    mutex _mtx;
    condition_variable _condition;
public:
    ThreadPool(int max):_max(max) {
        
    }

    virtual ~ThreadPool(){
        this->stop();

        while(!_tasks.empty()) {
            auto t = _tasks.front();
            delete t;
            _tasks.pop();
        }
    }

    void start() {
        for (int i = 0; i < _max; i++) {
            _threads.push_back(new thread(&ThreadPool::work, this));
        }
    }

    void stop() {
        for (auto t : _threads) {
            t->join();
            delete t;
        }
        _threads.clear();
    }

    void work() {
        while(true) {
            ThreadTask* task = getOneTask();
            if (task){
                task->runTask();
                delete task;
            } else {
                std::this_thread::sleep_for(chrono::microseconds(1));
            }
        }
    }

    void addTask(ThreadTask* task){
 //       unique_lock<mutex> lock(_mtx);
        _tasks.push(task);
   //     _condition.notify_one();
    }

    ThreadTask* getOneTask() {
        ThreadTask* p = nullptr;
        unique_lock<mutex> lock(_mtx);//有lock
        if (_tasks.empty()) {
            _condition.wait(lock);
        } else{
            p = _tasks.front();
            _tasks.pop();
        }
        return p;//unlock
    }
};

void add(int& a) {
    int n = 2;
    while(n--) {
        cout << " a = " << a << " thread_id = " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main() {
    ThreadPool pool(5);
    int n = 10;
    for (int i = 0; i < n; i++) {
        pool.addTask(new ThreadTask(add, i));
    }
    pool.start();
    return 0;
}
