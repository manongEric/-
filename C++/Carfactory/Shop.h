/*************************************************************************
	> File Name: Shop.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 04:25:16 PM CST
 ************************************************************************/

#ifndef _SHOP_H
#define _SHOP_H
#include<string>
#include<queue>

class OrderInfo;
class Shop{
private:
    const std::string shopid;
    std::queue<OrderInfo*> _orders; //维护4S店订货队列，用于下单
public:
    Shop(char* name);
    ~Shop();
public:
    virtual void applyBmwOrder();//申请订单
    virtual void applyAudiOrder();
    virtual void applyBenzOrder();
    virtual void onOrderFinish(OrderInfo* order); //工厂订单处理完后通知商店
    inline const std::string& id() {return shopid;};//获取4S店名
};
#endif
