/*************************************************************************
	> File Name: Audi.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:53:16 PM CST
 ************************************************************************/

#include<iostream>
#include "Audi.h"
#include "Factory.h"
#include<ctime>
using namespace std;

Audi::Audi(){

}

Audi::~Audi(){
    
}

void Audi::assemble(const OrderInfo* order) {
    this->name = order->brand + " " + order->serial;
    this->color = order->color;
    this->engine = order->engine;
    this->wheel = order->wheel;
    this->seat = order->seat;
    time_t now = time(0);
    this->date = ctime(&now);
}

void Audi::run(){
    std::cout << "Audi is Running" << std::endl;
}

void Audi::didi(){
    std::cout << "Audi is DIDI" << std::endl;
}
