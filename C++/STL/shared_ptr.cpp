/*************************************************************************
	> File Name: shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Jul 2022 03:55:02 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;


struct A{
    A(int n):x(n) {
        cout << "int constructor  " << this << endl;
    };
    A() {
        cout << "constructor  " << this << endl;
    }
    ~A(){
        cout << "destructor  "<< this << endl;    
    }
    int x;
};

int main() {
    shared_ptr<A> p1;
    shared_ptr<A> p2 = make_shared<A>(123);
    shared_ptr<A> p3(new A());
    //所有shared_ptr只要维护同一片地址，那么它指向的引用计数内存空间是同一片内存
    p1 = p2;//指向同一地址的shared_ptr引用计数空间是同一块内存, 调用了p1的赋值重载
    shared_ptr<A> p4 = p2;

    cout << "p1 count = " << p1.use_count() << " unique = " << p1.unique() << " point = " << p1.get() << endl;
    cout << "p2 count = " << p2.use_count() << " unique = " << p2.unique() << " point = " << p2.get() << endl;
    cout << "p3 count = " << p3.use_count() << " unique = " << p3.unique() << " point = " << p3.get() << endl;
    cout << "p4 count = " << p4.use_count() << " unique = " << p4.unique() << " point = " << p4.get() << endl;
    cout << p2.get()->x << " " << p2->x << endl;
    if (p1) {
        cout << p1->x << endl;
    } else {
        cout << "p1 is nullptr" << endl;
    }
    
    cout << "======================" << endl;
    p1.reset();//引用计数 - 1， 减到0才会析构
    p2.reset();
    p3.reset();
    cout << "======================" << endl;
    return 0;
}
