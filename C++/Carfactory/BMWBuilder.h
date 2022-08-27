/*************************************************************************
	> File Name: BMWBuilder.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 03:34:06 PM CST
 ************************************************************************/

#ifndef _BMWBUILDER_H
#define _BMWBUILDER_H
#include "BMWBuilder.h"
#include "Builder.h"
class BMWBuilder : public Builder {
private:

public:
    BMWBuilder();
    ~BMWBuilder();

public:
    void buildStart() override;
    void buildProcess() override;
    void buildFinish() override;
};
#endif
