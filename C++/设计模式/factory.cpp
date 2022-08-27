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

class Factory{
public:
    Car* getCar(std::string name) {
        if (name == "BMW") {
            return new BMW();
        } else if (name == "Benz") {
            return new Benz();
        } else {
            cout << "can not create " << name << endl;
            return nullptr;
        }
    }
};

int main() {
    Factory factory;
    Car* arr[5];
    for (int i = 0; i < 5; i++) arr[i] = nullptr;
    arr[0] = factory.getCar("BMW");
    arr[1] = factory.getCar("Benz");
    arr[2] = factory.getCar("Audi");
    arr[3] = factory.getCar("TOYOTO");
    arr[4] = factory.getCar("Lexus");

    /*arr[0]->printName();
    arr[1]->printName();*/
 //   cout << arr[2] << endl;
    for (auto it : arr) {
        if (it) {
            it->printName();
        }else {
            cout << " object is null "  << endl;
        }
    }
  //  delete[] arr;
    return 0;
}
