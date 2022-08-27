/*************************************************************************
	> File Name: Benz.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:48:45 PM CST
 ************************************************************************/

#ifndef _Benz_H
#define _Benz_H
#include "Car.h"

class Benz : public Car{
private:

public:
    Benz();
    ~Benz();

    virtual void assemble(const OrderInfo* order) override;
    virtual void run() override;
    virtual void didi() override;
};


#endif
