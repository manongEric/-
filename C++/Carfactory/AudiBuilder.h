/*************************************************************************
	> File Name: AudiBuilder.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 03:34:06 PM CST
 ************************************************************************/

#ifndef _AUDIBUILDER_H
#define _AUDIBUILDER_H
#include "Builder.h"
class AudiBuilder : public Builder {
private:

public:
    AudiBuilder();
    ~AudiBuilder();

public:
    void buildStart() override;
    void buildProcess() override;
    void buildFinish() override;
};
#endif
