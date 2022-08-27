/*************************************************************************
	> File Name: AudiBuilder.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 04:06:14 PM CST
 ************************************************************************/

#include<iostream>
#include "AudiBuilder.h"
#include "Factory.h"
#include "Audi.h"
using namespace std;

AudiBuilder::AudiBuilder():Builder("Audi") {

}

AudiBuilder::~AudiBuilder(){
    
}

void AudiBuilder::buildStart(){
    std::cout << "Audi汽车制造开始！ " << _currentOrder->shopid;
    std::cout << " - " << _currentOrder->brand;
    std::cout << " - " << _currentOrder->serial << std::endl;
}

void AudiBuilder::buildProcess(){
    std::cout << "Audi汽车制造中 " << _currentOrder->shopid << std::endl;
    Audi* car = new Audi();
    _currentOrder->car = car;
    car->assemble(_currentOrder);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void AudiBuilder::buildFinish(){
    std::cout << "Audi汽车制造完成 " << std::endl;
    Factory::instance()->onOrderFinished(_currentOrder); //回调订单工厂
    _workState = S_WAIT;
    _currentOrder = nullptr;
}
