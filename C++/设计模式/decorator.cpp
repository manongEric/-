/*************************************************************************
	> File Name: decorator.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2022 02:49:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//装饰者与被装饰的基类
class AbstractPerson{
public:
    virtual ~AbstractPerson(){}
    virtual void run() = 0;
    virtual void walk() = 0;
};

//被装饰类
class Person : public AbstractPerson{
public:
    Person(){}
    ~Person(){}

    void run() override{
        cout << "Person run " << endl;
    }

    void walk() override{
        cout << "Person walk " << endl;
    }
};

//装饰类， 继承基类，才知道要装饰什么方法
class AbstractDecorator : public AbstractPerson{
public:
    AbstractDecorator(AbstractPerson *p) : _person(p) {//维护装饰对象的指针

    }

    void run() override{
        cout << "Decorator Person Run! " << endl;
        _person->run();
    }

    void walk() override{
        cout << "Decorator Person Walk! " << endl;
        _person->walk();
    }
protected:
    AbstractPerson* _person; // 不同要装饰的对象
};

class PersonBlack : public AbstractDecorator {
public:
    PersonBlack(AbstractPerson* p): AbstractDecorator(p){}
    ~PersonBlack(){}

    void run() override{
        cout << "Black Person Run!" << endl;//装饰
        _person->run();//这里访问的是被装饰类Person的方法
        _person->run();
    }

    void walk() override{
        cout << "Black Person walk" << endl;
        _person->walk();
    }
};

class PersonOld : public AbstractDecorator {
public:
    PersonOld(AbstractPerson* p): AbstractDecorator(p){}
    ~PersonOld(){}

    void run() override{
        cout << "Old Person Can Not Run!" << endl;
    }

    void walk() override{
        cout << "Old Person walk slowly!" << endl;
        _person->walk();
    }
};

//外部可调用接口
void excuteRun(AbstractPerson* p) {
    p->run();
}

void excuteWalk(AbstractPerson* p) {
    p->walk();
}

int main() {
    AbstractPerson* p = new Person();//这里可以看出 p 是指向被装饰者对象
    excuteRun(p);
    excuteWalk(p);

    PersonBlack* p1 = new PersonBlack(p);
    PersonOld* p2 = new PersonOld(p);

    cout << "============decorator black===========\n";
    excuteRun(p1);
    excuteWalk(p1);

    cout << "============decorator old===========\n";
    excuteRun(p2);
    excuteWalk(p2);
    
    delete p1;
    delete p2;
    delete p;
    return 0;
}
