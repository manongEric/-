/*************************************************************************
	> File Name: Audi.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:48:45 PM CST
 ************************************************************************/

#ifndef _AUDI_H
#define _AUDI_H
#include "Car.h"

class Audi : public Car{
private:

public:
    Audi();
    ~Audi();

    virtual void assemble(const OrderInfo* order) override;
    virtual void run() override;
    virtual void didi() override;
};


#endif
