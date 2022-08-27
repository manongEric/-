/*************************************************************************
	> File Name: IAutoTest.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 03:53:15 PM CST
 ************************************************************************/

#ifndef _IAUTOTEST_H
#define _IAUTOTEST_H
class Car;
class OrderInfo;
class IAutoTest{
public:
    virtual void testRun(Car* car) = 0;
    virtual void testDIDI(Car* car) = 0;
    virtual bool testAll(OrderInfo* order) = 0;
};
#endif
