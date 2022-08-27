/*************************************************************************
	> File Name: proto.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Jul 2022 04:12:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class AbstractProto{
public:
    virtual ~AbstractProto(){}

    virtual AbstractProto* clone() = 0;
    virtual void debug() = 0;
};

class ProtoTypeA : public AbstractProto{
public:
    AbstractProto* clone() override{
        return new ProtoTypeA(*this);//我们是对自己的拷贝，使用当前的对象调用拷贝构造;
    }

    void debug() override{
        cout << this << " ProtoTypeA" << endl;
    }
};

class ProtoTypeB : public AbstractProto{
public:
    AbstractProto* clone() override{
        return new ProtoTypeB(*this);//我们是对自己的拷贝，使用当前的对象调用拷贝构造;
    }

    void debug() override{
        cout << this << " ProtoTypeB" << endl;
    }
};

int main() {
    AbstractProto* p1 = new ProtoTypeA();//开发时，不一定知道这里是TypeA的类型 
    AbstractProto* p2 = new ProtoTypeB();
    AbstractProto* p3 = p1->clone();
    AbstractProto* p4 = p2->clone();
    
    AbstractProto* p1 = new ProtoTypeAA();
    //都可以成功，这里就无法通过一个类对象确定p1是哪个具体类型
    dynamic_cast<ProtoTypeA*>(p1);
    dynamic_cast<ProtoTypeAA*>(p1);
    p1->debug();
    p2->debug();
    p3->debug();
    p4->debug();

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}
