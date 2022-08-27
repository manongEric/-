/*************************************************************************
	> File Name: Factory.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 03:29:59 PM CST
 ************************************************************************/

#ifndef _FACTORY_H
#define _FACTORY_H
#include<thread>
#include<mutex>
#include<map>
#include<vector>
#include<queue>

#include "ShopDelegate.h"
#include "IBuilderDelegate.h"
#include "IAutoTest.h"
#include "Builder.h"
//用来与4S店交互的接口类
class Car;
struct OrderInfo{
    std::string shopid;
    std::string brand;
    std::string serial;
    float engine;
    int seat;
    int wheel;
    long color;
    Car* car;

    static OrderInfo* create(std::string shop,std::string brand,std::string serial, float engine, int seat, int wheel, long color) {
        OrderInfo *pInfo = new OrderInfo();
        pInfo->shopid = shop;
        pInfo->brand = brand;
        pInfo->serial = serial;
        pInfo->engine = engine;
        pInfo->seat = seat;
        pInfo->wheel = wheel;
        pInfo->color = color;
        pInfo->car = nullptr;
        return pInfo;
    }
};
class Factory : public ShopDelegate, public IBuilderDelegate, public IAutoTest {
private:
    static Factory* _instance;
    std::thread* _thread; // 创建线程
    std::mutex _mtx;//创建互斥量
    //店铺
    std::map<std::string, Shop*> _shops;
    //待处理订单
    std::queue<OrderInfo*> _pendingOrders;
    //订单状态队列 : 标记订单现在是未处理还是处理完毕
    std::map<OrderInfo*, bool> _orders;
    //builder 对象
    std::vector<Builder*> _builders;
public:
    Factory();
    ~Factory();
public:
    static Factory* instance();//单例模式，调用静态方法相当于获得静态成员信息以实例化
    void startThread();//启动线程
    void stopThread();//停止线程
    void workThread();//线程工作
    

    //IShopDelegate
    void registerShop(Shop* shop);
    void addOrder(OrderInfo* order);//向工厂下订单

    //IBuiderDelegate
    virtual void onOrderFinished(OrderInfo* order);
    virtual void dealOrder();
    virtual Builder* addBuilder(OrderInfo* order);
    virtual void reduceBuilder();
    virtual Builder* getAvalidBuilder(OrderInfo* order);

    //IAutoTest
    virtual void testRun(Car* car);
    virtual void testDIDI(Car* car);
    virtual bool testAll(OrderInfo* order);

};
#endif
