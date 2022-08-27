/*************************************************************************
	> File Name: Benz.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:53:16 PM CST
 ************************************************************************/

#include<iostream>
#include "Benz.h"
#include "Factory.h"
#include<ctime>
using namespace std;

Benz::Benz(){

}

Benz::~Benz(){
    
}

void Benz::assemble(const OrderInfo* order) {
    this->name = order->brand + " " + order->serial;
    this->color = order->color;
    this->engine = order->engine;
    this->wheel = order->wheel;
    this->seat = order->seat;
    time_t now = time(0);
    this->date = ctime(&now);
}

void Benz::run(){
    std::cout << "Benz is Running" << std::endl;
}

void Benz::didi(){
    std::cout << "Benz is DIDI" << std::endl;
}
