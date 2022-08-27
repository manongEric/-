/*************************************************************************
	> File Name: single.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Jul 2022 02:40:03 PM CST
 ************************************************************************/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
class Singleton{
public:
    static Singleton* instance();
    static Singleton* _instance;
    static mutex _mtx;
};

Singleton* Singleton::instance(){
    if (_instance == nullptr) {
        _mtx.lock();
        
        if (_instance == nullptr)
            _instance = new Singleton();
        
        _mtx.unlock();
    }

    return _instance;
}

Singleton* Singleton::_instance = nullptr;
mutex Singleton::_mtx;
void getInstance(){
    cout << "instance = " << Singleton::instance() << endl;
}

int main() {
    thread t1(getInstance);
    thread t2(getInstance);
    thread t3(getInstance);
    
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
