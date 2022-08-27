/*************************************************************************
	> File Name: facade.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2022 03:44:42 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


//抽象系统类
class AbstractFacade{
public:
    virtual ~AbstractFacade(){}
    virtual bool Register() = 0;
    virtual bool Login() = 0;
};

class SystemA : public AbstractFacade{
public:
    SystemA(){}
    ~SystemA(){}

    bool Register() override{
        cout << "SystemA Register" << endl;
        return true;
    }

    bool Login() override{
        cout << "SystemA Login" << endl;
        return true;
    }
};

class SystemB : public AbstractFacade{
public:
    SystemB(){}
    ~SystemB(){}

    bool Register() override{
        cout << "SystemB Register" << endl;
        return true;
    }

    bool Login() override{
        cout << "SystemB Login" << endl;
        return true;
    }
};
class SystemC : public AbstractFacade{
public:
    SystemC(){}
    ~SystemC(){}

    bool Register() override{
        cout << "SystemC Register" << endl;
        return true;
    }

    bool Login() override{
        cout << "SystemC Login" << endl;
        return true;
    }
};
//系统接口类
class Facace : public AbstractFacade{
public:
    Facace(){}
    ~Facace(){}
    
    bool Register() override{
        for (auto p : _systems) {
            p->Register();
        }
        return true;
    }

    bool Login() override{
        for (auto p : _systems) {
            p->Login();
        }
        return true;
    }
    
    void addSystem(AbstractFacade* sys) {
        _systems.push_back(sys);
        return;
    }
private:
    vector<AbstractFacade*> _systems;
};

int main() {
    Facace facace;
    AbstractFacade* p1 = new SystemA();
    AbstractFacade* p2 = new SystemB();
    AbstractFacade* p3 = new SystemC();
    facace.addSystem(p1);
    facace.addSystem(p2);
    facace.addSystem(p3);

    facace.Register();
    facace.Login();

    delete p1;
    delete p2;
    delete p3;


    return 0;
}
