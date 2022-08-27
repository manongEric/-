/*************************************************************************
	> File Name: factory.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Jul 2022 02:52:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Car{
protected:
    int wheel;
    int engine;
    int color;
public:
    virtual ~Car(){}
    virtual void debug() = 0;
    virtual void printName() = 0;
};

class BMW : public Car{
    void printName() override{
        cout << "Name = " << "BMW" << endl;
    }
    void debug() override{
        cout << "name = " << "BMW" << wheel << " " << engine << " " << color << " " << endl;
    }
};

class Benz : public Car{
    void printName() override{
        cout << "Name = " << "Benz" << endl;
    }
    void debug() override{
        cout << "name = " << "Benz" << wheel << " " << engine << " " << color << " " << endl;
   }
    
};
class AbstractBuilder{
public:
    virtual void builderA() = 0;
    virtual void builderB() = 0;
    virtual void builderC() = 0;
    virtual Car* getCar() = 0;
};
class BMWBuilder : public AbstractBuilder {
public:
    void builderA() override {
        cout << "BMW build A" << endl;
    }
    void builderB() override {
        cout << "BMW build B" << endl;
    }
    void builderC() override {
        cout << "BMW build C" << endl;
    }
    Car* getCar() {
        Car* car = new BMW();
        builderA();
        builderB();
        builderC();
        return car;
    }
};
class BenzBuilder : public AbstractBuilder {
public:
    void builderA() override {
        cout << "Benz build A" << endl;
    }
    void builderB() override {
        cout << "Benz build B" << endl;
    }
    void builderC() override {
        cout << "Benz build C" << endl;
    }
    Car* getCar() {
        Car* car = new Benz();
        builderA();
        builderB();
        builderC();
        return car;
    }
};
class Director{//中介
public:
    AbstractBuilder* _builder;//联系建造商
public:
    void setBuilder(AbstractBuilder* builder) {//核心：需要建造时，使用不同的建造者建造汽车  
        _builder = builder;
    }

    Car* getCar() { 
        return _builder->getCar();
    }
};

int main() {
    Director director;
    BMWBuilder* builder1 = new BMWBuilder();//首先实例化底层建造商
    BenzBuilder* builder2 = new BenzBuilder();
    director.setBuilder(builder1);//联系品牌建造商
    auto car1 = director.getCar();//品牌建造商，开始建造细节，并完工
    car1->debug();
    delete car1;
    
    director.setBuilder(builder2);
    auto car2 = director.getCar();
    car2->debug();
    delete car2;
    

    delete builder1;
    delete builder2;
    return 0;
}
