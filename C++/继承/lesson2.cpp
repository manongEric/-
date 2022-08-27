/*************************************************************************
	> File Name: lesson2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Jul 2022 06:24:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    int n;
public:
    void run() {
        cout << "A run" << endl;
    }
};

class B : virtual public A{//虚继承
public:
    int m;
public:
    void run() {
        cout << "B run" << endl;
    }
};
class C : virtual public A{//虚继承
public:
    int l;
public:
    void run() {
        cout << "C run" << endl;
    }
};

class D : public B, public C{//B,C虚继承A，占40字节  虚函数表在前，最后A::n的信息在D类只有一份拷贝
public:
    int k;
public:
    void run() {
        cout << "c run" << endl;
    }
};

int main() {
    D *pd = new D();
    cout << "size of D: " << sizeof(D) << endl;
   
    pd->B::run();//不能调用A::run ,因为在B，C中都有一份拷贝
    cout << "address of n" << &pd->B::n << endl;
    return 0;
}
