/*************************************************************************
	> File Name: _main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 04:04:10 PM CST
 ************************************************************************/

#include<iostream>
#include "Factory.h"
#include "Shop.h"
using namespace std;

int main() {
    Shop* shop = new Shop("Audi-Shop");
    //shop->applyBmwOrder();
    //shop->applyBmwOrder();
    //shop->applyBmwOrder();


    //Factory::instance()->startThread();
    Factory::instance();
    while(true) {
        shop->applyAudiOrder();
        //shop->applyAudiOrder();
        //shop->applyAudiOrder();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
    }
    delete shop;
    return 0;
}
