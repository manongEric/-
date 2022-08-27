/*************************************************************************
	> File Name: IBuilderDelegate.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2022 03:47:52 PM CST
 ************************************************************************/

#ifndef _IBUILDERDELEGATE_H
#define _IBUILDERDELEGATE_H
class Builder;
class OrderInfo;
class IBuilderDelegate{
public:
    //订单完成，回调工厂
    virtual void onOrderFinished(OrderInfo* order) = 0;
    //处理订单
    virtual void dealOrder() = 0;
    //新增流水线
    virtual Builder* addBuilder(OrderInfo* order) = 0;
    //减少流水线
    virtual void reduceBuilder() = 0;
    //判断可用流水线
    virtual Builder* getAvalidBuilder(OrderInfo* order) = 0;
};
#endif
