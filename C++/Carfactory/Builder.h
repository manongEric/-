/*************************************************************************
	> File Name: Builder.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 02:34:32 PM CST
 ************************************************************************/

#ifndef _BUILDER_H
#define _BUILDER_H
#include<string>
#include<thread>
#include<mutex>
enum STATE{
    S_WAIT,
    S_WORK,
    S_SLEEP
};
class OrderInfo;
class Builder{
protected:
    std::string _name;
    OrderInfo* _currentOrder;//订单信息

    STATE _workState;
    std::thread* _thread;//流水线的线程
    std::mutex _mtx;
public:
    Builder(char* name);
    ~Builder();
    inline const std::string& name(){return _name;}
    virtual void applyOrder(OrderInfo* order);//流水线接受订单
    virtual void buildCar();

    virtual void startThread();
    virtual void stopThread();
    virtual void workThread();
   
    virtual bool isValid(){return _workState == S_WAIT;}
public:
    virtual void buildStart() = 0;
    virtual void buildProcess() = 0;
    virtual void buildFinish() = 0;
};
#endif
