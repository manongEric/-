/*************************************************************************
	> File Name: BenzBuilder.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 03:34:06 PM CST
 ************************************************************************/

#ifndef _BenzBUILDER_H
#define _BenzBUILDER_H
#include "BenzBuilder.h"
#include "Builder.h"
class BenzBuilder : public Builder{
private:

public:
    BenzBuilder();
    ~BenzBuilder();

public:
    void buildStart() override;
    void buildProcess() override;
    void buildFinish() override;
};
#endif
