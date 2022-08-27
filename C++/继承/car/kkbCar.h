/*************************************************************************
	> File Name: kkbcar.h
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2022 09:08:21 PM CST
 ************************************************************************/

#ifndef _KKBCAR_H
#define _KKBCAR_H
#include<string>
class kkbCar{
private:
    unsigned long color;
    float engine;
    int wheel;
    int seat;
    long date;
public:
    kkbCar();
    virtual ~kkbCar();
    virtual void run() = 0;
    virtual void didi() = 0;
};
#endif
