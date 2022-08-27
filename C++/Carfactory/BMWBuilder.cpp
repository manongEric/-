/*************************************************************************
	> File Name: BMWBuilder.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 04:06:14 PM CST
 ************************************************************************/

#include<iostream>
#include "BMWBuilder.h"
#include "Factory.h"
#include "BMW.h"
using namespace std;

BMWBuilder::BMWBuilder():Builder("BMW") {

}

BMWBuilder::~BMWBuilder(){
    
}

void BMWBuilder::buildStart(){
    std::cout << "BMW汽车制造开始！ " << _currentOrder->shopid;
    std::cout << " - " << _currentOrder->brand;
    std::cout << " - " << _currentOrder->serial << std::endl;
}

void BMWBuilder::buildProcess(){
    BMW* car = new BMW();
    _currentOrder->car = car;
    car->assemble(_currentOrder);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void BMWBuilder::buildFinish(){
    std::cout << "BMW汽车制造完成 " << std::endl;
    Factory::instance()->onOrderFinished(_currentOrder); //回调订单工厂
    _workState = S_WAIT;
    _currentOrder = nullptr;
}
