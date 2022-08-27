/*************************************************************************
	> File Name: kkbBuilder.h
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2022 09:16:42 PM CST
 ************************************************************************/

#ifndef _KKBBUILDER_H
#define _KKBBUILDER_H
#include "string"
#include "kkbCar.h"

class kkbBuilder{
private:
    std::string name;
public:
    kkbBuilder();
    ~kkbBuilder();

    virtual kkbCar* build() = 0;
    virtual void fix(kkbCar* pCar) = 0;
};
#endif
