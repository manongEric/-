/*************************************************************************
	> File Name: BenzBuilder.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 04:06:14 PM CST
 ************************************************************************/

#include<iostream>
#include "BenzBuilder.h"
#include "Factory.h"
#include "Benz.h"
using namespace std;

BenzBuilder::BenzBuilder():Builder("Benz") {

}

BenzBuilder::~BenzBuilder(){
    
}

void BenzBuilder::buildStart(){
    std::cout << "Benz汽车制造开始！ " << _currentOrder->shopid;
    std::cout << " - " << _currentOrder->brand;
    std::cout << " - " << _currentOrder->serial << std::endl;
}

void BenzBuilder::buildProcess(){
    Benz* car = new Benz();
    _currentOrder->car = car;
    car->assemble(_currentOrder);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void BenzBuilder::buildFinish(){
    std::cout << "Benz汽车制造完成 " << std::endl;
    Factory::instance()->onOrderFinished(_currentOrder); //回调订单工厂
    _workState = S_WAIT;
    _currentOrder = nullptr;
}
