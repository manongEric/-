/*************************************************************************
	> File Name: lesson1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Jul 2022 03:34:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
struct objectA{
    objectA(){
        cout << "objectA constructor" << endl;
    }
    ~objectA(){
        cout << "objectA desconstructor" << endl;
    }
};
struct objectB{
    objectB(){
        cout << "objectB constructor" << endl;
    }
    ~objectB(){
        cout << "objectB desconstructor" << endl;
    }
};
class A{
private:
    int _m;
    objectA oa;
    objectB ob;
public:
    A():ob(), oa(){//初始化顺序，不影响构造顺序，构造顺序看定义顺序
        cout << "A constructor" << endl;
    }
    A(int m):_m(m) {
        cout << "A int constructor" << endl;
    }
    virtual ~A(){
        cout << "A desconstructor" << endl;
    }
    void f(){
        cout << "function A::f" << endl;
    }
    virtual void g() {
        cout << "function A::g" << endl;
    }
};

class B : public A{
public:
    int _n;
public:
    B(){//默认 B():A()
        cout << "B constructor" << endl;
    }
    B(int m):A(m), _n(m){//需要显示调用
        cout << "B int constructor" << endl;
    }
    B(const B& b):A(b) {
        
    }
    void operator=(const B& b) {
        A::operator=(b);
    }
    virtual ~B(){
        cout << "B desconstructor" << endl;
    }
    void f(){
        cout << "function B::f" << endl;
    }
    void g() override{//代表重写虚方法
        cout << "function B::g" << endl;
    }
};

int main() {
 /*  // B b(1); //先进行父类构造，再进行子类构造
   // b.f();
   // b.g();

    B* pb = new B();
    pb->f();//B::f
    pb->g();//B::g
    
    A* pa = pb;//父类指针可以指向子类, 子类指针不能指向父类,少的可以给多的，多的不能给少的,子类信息更多
    //A *pa = (A*)pb;
    pa->f();//A::f
    pa->g();//B::g  不管什么指针，一定是访问重写后的虚方法，因为在内存中已经被替换，而父子类的普通方法都是各个属于各个的，强转也没有用，普通方法跟指针走

    //B* pb2 = (B*)pa;//强制转换的一种方式
    //B* p
    //b3 = dynamic_cast<B*>(pa);//子类指针指向父类需要强制类型转换
    cout << "==============" << endl;
    A a;//构造顺序和析构顺序相反
    cout << "==============" << endl;
    A *pA = new B();
    delete pA;*///此时若A的析构函数不是虚方法，则不会析构B只会析构A，因为此时A已经沦为普通方法，普通方法跟着指针走，因此析构函数要加上虚方法，让父类指针析构时能从父类指向子类，再转回父类,避免内存泄露,动态多态
    cout << "==========" << endl;
    B *pb = new B();
    pb->A::f();//以域名的方式，通过子类指针，访问父类方法,如果不加，普通方法跟指针走

    return 0;

}
