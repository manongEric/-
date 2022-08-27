/*************************************************************************
	> File Name: thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Jul 2022 10:42:41 PM CST
 ************************************************************************/

#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
using namespace std;

mutex mtx;

void print(int n) {
    for (int i = 0; i <= n; i++) {
        mtx.lock();
        cout << i;
        cout << endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void add(int &n) {
    for (int i = 1; i <= 100000; i++) {
        mtx.lock();
        n++;
        mtx.unlock();
    }
}

void add2(atomic<int>& n) {
    for (int i = 1; i <= 100000; i++) {
        n++;
    }
}
int main() {
    int m = 0;
    thread t1(add, ref(m));
    thread t2(add, ref(m));
    auto t = clock();
    t1.join();
    t2.join();
    cout << "mutex final value m = " << " time = " << clock() - t << endl;

    t = clock();
    atomic<int> n{0}; //原子操作，只有基本类型才可以使用

    thread t3(add2, ref(n));
    thread t4(add2, ref(n));
    t3.join();
    t4.join();
    cout << "atomic final value m = " << " time = " << clock() - t << endl;
   /* thread p1(print, 10);
    thread p2(print, 10);

    p1.join();//把p1线程加入当前主线程， 此时主线程处于阻塞状态等待子线程结束
    p2.join();//把p1线程加入当前主线程， 此时主线程处于阻塞状态等待子线程结束
    */
    return 0;
}
