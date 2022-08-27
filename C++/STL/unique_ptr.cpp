/*************************************************************************
	> File Name: unique_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Jul 2022 03:13:57 PM CST
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
    //3种创建方式
    unique_ptr<A> p1;
    unique_ptr<A> p2 = make_unique<A>(123);
    unique_ptr<A> p3(new A());

    if (p1) //p1创建出来，还没有套用
        cout << p1->x << endl;
    cout << "两种智能指针取类属性的方式" << endl;
    cout << p2->x << endl;
    A* p = p3.get();
    cout << p3->x << endl;

    cout << "=========================" << endl;
   // A *point = p2.release();//release 抛出控制权，由point接受，因此，一定要手动delete
    //p2.reset(); reset相当于抛出控制的指针所有权并且delete，直接调用析构函数
    p1 = move(p2);//C++move是为了转移所有权，将快要销毁的对象转移给其他变量，这样可以继续使用这个对象，而不必再创建一个一样的对象。
    cout << "p1 : " << p1.get() << " p2 : " << p2.get() << endl;
    p1.swap(p2);//也是一种交换的方式
    cout << "p1 : " << p1.get() << " p2 : " << p2.get() << endl;
   // delete point;
    cout << "=========================" << endl;
    return 0;
}
