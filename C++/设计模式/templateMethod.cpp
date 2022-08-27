/*************************************************************************
	> File Name: templateMethod.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2022 04:29:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Factory{
public:
    virtual void buildCar(){//方法封装在基类,不需要子类每个实现一份
        this->buildA();
        this->buildB();
        this->buildC();
    }
    virtual void buildA() = 0;
    virtual void buildB() = 0;
    virtual void buildC() = 0;
};

class FactoryBMW : public Factory{
public:
    void buildA() {
        cout << "BMW build A" << endl;
    }
    void buildB() {
        cout << "BMW build B" << endl;
    }
    void buildC() {
        cout << "BMW build C" << endl;
    }
};
class FactoryBenz : public Factory{
public:
    void buildA() {
        cout << "Benz build A" << endl;
    }
    void buildB() {
        cout << "Benz build B" << endl;
    }
    void buildC() {
        cout << "Benz build C" << endl;
    }
};

int main() {
    Factory* p1 = new FactoryBMW();
    Factory* p2 = new FactoryBenz();

    p1->buildCar();
    p2->buildCar();

    delete p1;
    delete p2;

    return 0;
}
