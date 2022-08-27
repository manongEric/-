/*************************************************************************
	> File Name: chain.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Aug 2022 11:00:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
struct Request{
    int days;
    int type;
    string desc;
};

class Handler{
public:
    Handler(){}
    virtual ~Handler(){}

    virtual void setNextHandler(Handler* p) {_nextHandler = p;}
    virtual void dealRequest(Request* p) = 0;
    virtual void request(int days, int type, string desc) {
        Request* p = new Request{ days, type, desc};
        this->dealRequest(p);
        delete p;
    }
protected:
    Handler* _nextHandler;
};

class Employee : public Handler {
public:
    void dealRequest(Request* p) override{
        cout << "Employee : 没有权限，需要上级审批\n";
        if (this->_nextHandler)
            this->_nextHandler->dealRequest(p);
    }
};
class TeamLeader : public Handler {
public:
    void dealRequest(Request* p) override{
        if (p->days <= 3)
            cout << "TeamLeader : 小于三天， 直接pass\n";
        else {
            cout << "TeamLeader : 没有权限，需要上级审批\n";
            if (this->_nextHandler)
                this->_nextHandler->dealRequest(p);
        }
    }
};
class Manager : public Handler {
public:
    void dealRequest(Request* p) override{
        if (p->days <= 5)
            cout << "Manager: 小于5天， 直接pass\n";
        else {
            cout << "Manager : 没有权限，需要上级审批\n";
            if (this->_nextHandler)
                this->_nextHandler->dealRequest(p);
        }
    }
};
class Boss : public Handler {
public:
    void dealRequest(Request* p) override{
        if (p->days <= 10)
            cout << "Boss : 小于10天， 直接pass\n";
        else {
            cout << "Boss : 大于10天，拒接!\n";
            if (this->_nextHandler)
                this->_nextHandler->dealRequest(p);
        }
    }
};

int main() {
    Handler* p1 = new Boss();
    Handler* p2 = new Manager();
    Handler* p3 = new TeamLeader();
    Handler* p4 = new Employee();

    p4->setNextHandler(p3);
    p3->setNextHandler(p2);
    p2->setNextHandler(p1);

//    p4->request(2, 0, "事假");
    p4->request(15, 999, "病假");
    delete p4;
    delete p3;
    delete p2;
    delete p1;
    return 0;
}
