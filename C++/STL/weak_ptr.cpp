/*************************************************************************
	> File Name: weak_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Jul 2022 09:59:47 PM CST
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
    //weak_ptr必须和shared_ptr组合使用
    shared_ptr<A> sp = make_shared<A>(123);
    weak_ptr<A> p1(sp);
    {
       // p1.reset();
        shared_ptr<A> p = p1.lock();//引用计数 + 1，相当于shared_ptr，使用weak_ptr前lock, 通过lock的返回值使用指针
        if(p) {//正确使用weak_ptr的方式
            cout << "p locked = " << p << endl;
            cout << p->x << endl; 
        }else {
            cout << "p locked = " << p << endl;          
        }
        cout << p1.expired() << endl;//判断是否有效
        cout << p1.use_count() << endl;

    }
    cout << "after lock " << p1.use_count() << endl;
    return 0;
}
