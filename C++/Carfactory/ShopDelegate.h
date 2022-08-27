/*************************************************************************
	> File Name: ShopDelegate.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:14:50 PM CST
 ************************************************************************/

#ifndef _SHOPDELEGATE_H
#define _SHOPDELEGATE_H
class Shop;
class OrderInfo;
class ShopDelegate {
public:
    virtual void registerShop(Shop* shop) = 0;
    virtual void addOrder(OrderInfo* order) = 0;
};
#endif
