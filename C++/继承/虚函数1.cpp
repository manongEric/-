/*************************************************************************
	> File Name: 虚函数1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2022 03:11:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class IkeyBorad{//接口类,在类前加上大写的I
    virtual void onKeyDown(int keycode) = 0;
    virtual void onKeyPress(int keycode) = 0;
    virtual void onKeyRlease(int keycode) = 0;
};
class Node{//总基类
    float width;
    float height;
};

class EditBox : public Node, public IkeyBorad {//通过继承的方式，来重载接口类的全虚方法
    void onKeyDown(int keycode) {

    } 
    void onKeyPress(int keycode) {

    } 
    void onKeyRlease(int keycode) {

    } 
};

class Animal{
public:
    virtual ~Animal(){};
    virtual void run() = 0;//{//父类方法成为虚方法，这是动态多态执行的条件，从而在编译时，能让指针跟着不同对象走
      //  cout << "Animal run" << endl;
   // }
    virtual void eat() = 0;//{//这里声明为纯虚方法，子类要对父类方法进行重载，且animal类是不允许被实例化的
     //   cout << "Animal eat" << endl;
   // }
    virtual void say()  = 0;//{
     //   cout << "Animal say" << endl;
   // }
    
    void actionEat(){
        this->run();
        this->eat();
        this->say();
    }
};
class Cat : public Animal{
public:
    void run(){
        cout << "Cat run" << endl;
    }
    void eat(){
        cout << "Cat eat" << endl;
    }
    void say() {
        cout << "Cat say" << endl;
    }
};

class Dog : public Animal{
public:
    void run(){
        cout << "Dog run" << endl;
    }
    void eat(){
        cout << "Dog eat" << endl;
    }
    void say() {
        cout << "Dog say" << endl;
    }
};

int main() {
    Animal* animals[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 1) {
            animals[i] = new Cat();
        } else {
            animals[i] = new Dog();
        }
    }
    for (auto animal : animals) {
        animal->actionEat();
    }
    return 0;
}
