/*************************************************************************
	> File Name: rvo.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jun 2022 10:10:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
    private:
        int _n;
    public:
    /*explicit A(int n):_n(n) {//只能显示转换
        cout << "int construtor" << endl;
    }*/
    A() {
        cout << "default construtor" << endl;
    }
    A(int n):_n(n) {
        cout << "int construtor" << endl;
    }
    A(const A& a) {
        cout << "copy construtor" << endl;
    }
    ~A() {
        cout << "desconstructor" << endl;
    }

    void operator=(const A& a) {
        cout << "operator !" << endl;
    }

};
A func() {
    A temp(123);
    return temp;//A 的临时匿名变量的拷贝构造，与temp的析构；
}
class B{
    private:
        A da;
        A* pa;
    public://---da(*a) == A da = *a;
        B(A* a):da(*a), pa(new A(*a))//:后进行初始化，da(*a)我们传入的是A对象（*a 与函数原型const A& a），调用A对象的拷贝构造函数，一开始da对象还没有构造完成，只是分配内存
        {
            cout << "B copy construtor 1111" << endl;
        }
        B(A a) //先进行一次值传递的拷贝构造，再进行A的默认构造
        {
            cout << "B copy construtor 2222" << endl;
            this->da = a;//此时是赋值，而不是拷贝构造，因为类对象已经创建好了
            this->pa = new A(a);//new A(a)是拷贝构造，因为a不是一个整数而是对象
            //最后执行析构，把a对象释放
        }

};
int main() {
    A a;
    B b = &a;//B b(&a)
    cout << "=================" << endl; 
    B c = a;


    cout << "=================" << endl;
    A d = func();//包含A 的析构， 临时匿名变量的析构
    /*
    A a = 1;//能将1隐式转换为A，赋值给a这个对象，隐式的调用构造函数；

    //显示的调用构造函数
    A b(1);
    A c(1.0);
    A d(1.0f);*/
    A e(123);
    A f;// A f = e  ==  A f(e);, 
    f = e;
    return 0;
}
