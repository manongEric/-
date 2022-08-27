/*************************************************************************
	> File Name: Shop.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 04:30:38 PM CST
 ************************************************************************/

#include<iostream>
#include "Shop.h"
#include "Factory.h"
using namespace std;


Shop::Shop(char* name):shopid(name) {//shop创建时注册到factory中
    Factory::instance()->registerShop(this);
}
Shop::~Shop() {

}
void Shop::applyBmwOrder() {
    OrderInfo* order = OrderInfo::create(shopid, "BMW", "740", 9.0F, 4, 4, 0xffffff);//新建订单
    this->_orders.push(order);//将订单放进4S店订单状态队列
    Factory::instance()->addOrder(order);//工厂实例化订单
}
void Shop::applyAudiOrder() {
    OrderInfo* order = OrderInfo::create(shopid, "Audi", "A9", 6.0F, 4, 4, 0xffffff);//新建订单
    this->_orders.push(order);//将订单放进4S店订单状态队列
    Factory::instance()->addOrder(order);//工厂实例化订单
}
void Shop::applyBenzOrder(){
    OrderInfo* order = OrderInfo::create(shopid, "Benz", "SL680", 12.0F, 4, 4, 0xffffff);//新建订单
    this->_orders.push(order);//将订单放进4S店订单状态队列
    Factory::instance()->addOrder(order);//工厂实例化订单
    
}

void Shop::onOrderFinish(OrderInfo* order){//工厂通过4S店名完成订单后进行回调
    std::cout << "Order Finished [ car : " << order->car << " shop : " << this->shopid << std::endl;
}
