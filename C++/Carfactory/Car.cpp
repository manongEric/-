/*************************************************************************
	> File Name: Car.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:44:51 PM CST
 ************************************************************************/

#include<iostream>
#include "Car.h"
using namespace std;

Car::Car(){

};

Car::~Car(){
    
}
void Car::details(){
    std::cout << name << " Product Details :" << std::endl;
    std::cout << "color : " << color << std::endl;
    std::cout << "engine : " << engine << std::endl;
    std::cout << "wheel : " << wheel << std::endl;
    std::cout << "seat : " << seat << std::endl;
    std::cout << "date : " << date << std::endl;
}
