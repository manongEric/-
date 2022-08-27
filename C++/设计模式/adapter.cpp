/*************************************************************************
	> File Name: adapter.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Jul 2022 09:07:58 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Target{
public:
    virtual ~Target(){}
    virtual int request() = 0;
};

class Adaptee{
public:
    virtual ~Adaptee(){}
    virtual int specialRequest(){
        cout << "Adaptee special Request" << endl;
        return 999;
    }
};

class Adapter : public Target, public Adaptee{
public:
    int request() override{
        return this->specialRequest();
    }
};
//方法二  利用可使用适配对象指针传递的类桥接模式
class AAdapter : public Target{
private: 
    Adaptee* _adaptee;
public:
    AAdapter() = delete;
    AAdapter(Adaptee* p) : _adaptee(p) {
        
    }

    virtual ~AAdapter(){}

    int request() override{
        return _adaptee->specialRequest();
    }
};
void interfaceRequest(Target* target){
    auto ret = target->request();
    cout << "ret = " << ret << endl;
} 

int main(){
    Adapter* adapter = new Adapter();
    interfaceRequest(adapter);//向下转型
    delete adapter;

    Adaptee* adaptee = new Adaptee();
    Target* target = new AAdapter(adaptee);// 向下转型
    interfaceRequest(target);

    return 0;
}
