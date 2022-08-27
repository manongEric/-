/*************************************************************************
	> File Name: proxy.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2022 04:07:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Person{
public:
    Person():_delegate(nullptr){}
    virtual ~Person(){}

    virtual void rentHouse() = 0;
    virtual void setDelegate(Person* p){_delegate = p;}

protected:
    Person* _delegate;
};

class Proxy : public Person{
public:
    Proxy(){}
    ~Proxy(){}

    void rentHouse() override{
        cout << "Proxy help renthouse" << endl;
        cout << "Proxy Need Fees" << endl;
    }
};

class Master : public Person{
public:
    Master(){}
    ~Master(){}

    void rentHouse() override{
        if (!_delegate)
            return;
        
        cout << "Master Need RentHouse" << endl;
        _delegate->rentHouse();
    }

};

int main() {
    Person* m = new Master();
    Person* p = new Proxy();

    m->setDelegate(p);
    m->rentHouse();

    delete m;
    delete p;

    return 0;
}
