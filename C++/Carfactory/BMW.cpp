/*************************************************************************
	> File Name: BMW.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:53:16 PM CST
 ************************************************************************/

#include<iostream>
#include "BMW.h"
#include "Factory.h"
#include<ctime>
using namespace std;

BMW::BMW(){

}

BMW::~BMW(){
    
}

void BMW::assemble(const OrderInfo* order) {
    this->name = order->brand + " " + order->serial;
    this->color = order->color;
    this->engine = order->engine;
    this->wheel = order->wheel;
    this->seat = order->seat;
    time_t now = time(0);
    this->date = ctime(&now);
}

void BMW::run(){
    std::cout << "BMW is Running" << std::endl;
}

void BMW::didi(){
    std::cout << "BMW is DIDI" << std::endl;
}
