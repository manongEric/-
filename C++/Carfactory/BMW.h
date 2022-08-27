/*************************************************************************
	> File Name: BMW.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Jul 2022 06:48:45 PM CST
 ************************************************************************/

#ifndef _BMW_H
#define _BMW_H
#include "Car.h"

class BMW : public Car{
private:

public:
    BMW();
    ~BMW();

    virtual void assemble(const OrderInfo* order) override;
    virtual void run() override;
    virtual void didi() override;
};


#endif
