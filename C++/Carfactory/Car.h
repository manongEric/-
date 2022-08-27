/*************************************************************************
	> File Name: Car.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:16:41 PM CST
 ************************************************************************/

#ifndef _CAR_H
#define _CAR_H
class OrderInfo;
class Car{
protected:
    std::string name;
    unsigned long color;
    float engine;
    int wheel;
    int seat;
    std::string date;

public:
    Car();
    virtual ~Car();

    virtual void assemble(const OrderInfo* order) = 0;
    virtual void run() = 0;
    virtual void didi() = 0;
    virtual void details();
};
#endif
