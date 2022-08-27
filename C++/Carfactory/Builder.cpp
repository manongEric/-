/*************************************************************************
	> File Name: Builder.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 02:43:27 PM CST
 ************************************************************************/

#include<iostream>
#include "Builder.h"
using namespace std;

Builder::Builder(char* name):_name(name),_currentOrder(nullptr), _workState(S_SLEEP) {
    this->startThread();
}

Builder::~Builder(){
    this->stopThread();
}

void Builder::applyOrder(OrderInfo* order){
    _currentOrder = order;
}

void Builder::buildCar() {
    this->buildStart();
    this->buildProcess();
    this->buildFinish();
}

void Builder::startThread(){
    _workState = S_WAIT;

    if(_thread) stopThread();
    _thread = new std::thread(&Builder::workThread, this);
}

void Builder::stopThread(){
    if(_thread){
        _thread->join();
        delete _thread;
        _thread = nullptr;
    }
}

void Builder::workThread(){
    while(true) {
        if(_currentOrder && _workState == S_WAIT){
            _workState = S_WORK;
            _mtx.lock();
            this->buildCar();
            _mtx.unlock();
            _workState = S_WAIT;
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}
