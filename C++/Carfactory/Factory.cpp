/*************************************************************************
	> File Name: Factory.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 03:32:38 PM CST
 ************************************************************************/

#include "Factory.h"
#include "Shop.h"
#include "Car.h"
#include "Builder.h"
#include "BMWBuilder.h"
#include "BenzBuilder.h"
#include "AudiBuilder.h"
#include<iostream>
Factory* Factory::_instance = nullptr;
Factory* Factory::instance(){
    if (_instance == nullptr) {
        _instance = new Factory();
    }
    return _instance;
}

Factory::Factory(){
    
}

Factory::~Factory(){
    
}
void Factory::startThread() {
    _thread = new std::thread(&Factory::workThread, this);
}//启动线程

void Factory::stopThread(){
    if (_thread){
        _thread->join();//主线程阻塞，等待回收对应创建的线程的资源，避免造成资源的泄露;
        delete _thread;//释放开辟的新线程地址
        _thread = nullptr;//类成员中的线程置为空指针；
    }
}
void Factory::workThread(){
    std::cout << "开始处理订单" << std::endl;//轮询shop订单

    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        _mtx.lock();
        std::cout << "处理订单" << std::endl;
        this->dealOrder();
        _mtx.unlock();
    }
}
void Factory::registerShop(Shop* shop) {//标记提供订单的4S店名字，4S店在工厂登录
    _shops[shop->id()] = shop;
}

void Factory::addOrder(OrderInfo* order) {//这个时候是收到了4S店订单，放进订单处理队列，同时标记一下状态
    _mtx.lock();
    _pendingOrders.push(order);
    _orders[order] = false;
    _mtx.unlock();
}


//IBuiderDelegate
void Factory::onOrderFinished(OrderInfo* order) {
    auto orderData = _orders.find(order);
    if(orderData != _orders.end()) {
        orderData->second = true;
    }
    if (this->testAll(order)){
        auto shop = _shops.find(order->shopid);
        if(shop != _shops.end()){
            shop->second->onOrderFinish(order);
        }
    }
}
Builder* Factory::addBuilder(OrderInfo* order){
    Builder* builder = nullptr;

    if(order->brand == "Audi"){
        builder = new AudiBuilder();
    }else if(order->brand == "Benz"){
        builder = new BenzBuilder();
    } else if(order->brand == "BMW"){
        builder = new BMWBuilder();
    }

    this->_builders.push_back(builder);
    return builder;
}
void Factory::reduceBuilder() {

}
Builder* Factory::getAvalidBuilder(OrderInfo* order) {
    if (_builders.empty()){
        return this->addBuilder(order);
    } else{
        for(auto builder : _builders){
            if(builder->name() == order->brand) {
                if(builder->isValid()) {
                    return builder;
                } else {
                    std::cout << "当前流水线正在处理，请稍后! \n";
                }
            } else{
                return this->addBuilder(order);
            }
        }
    }
    return nullptr;
}
void Factory::dealOrder(){
    if (!_pendingOrders.empty()){
        auto order = _pendingOrders.front();
        std::cout << "待流水线处理, 订单数 = " << _pendingOrders.size() << std::endl;
        Builder* builder = this->getAvalidBuilder(order);
        if(builder){
            builder->applyOrder(order);
            _pendingOrders.pop();
        } else {
            std::cout << "当前没有可用的流水线， 当前订单数 ：" << _pendingOrders.size();
            std::cout << "当前流水线个数 : " << _builders.size() << std::endl;
        }
    }
}

//IAutoTest
void Factory::testRun(Car* car) {
    car->run();
}
void Factory::testDIDI(Car* car) {
    car->didi();
}
bool Factory::testAll(OrderInfo* order) {
    order->car->details();
    this->testRun(order->car);
    this->testDIDI(order->car);
    return true;
}
