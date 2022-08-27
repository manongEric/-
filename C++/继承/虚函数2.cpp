/*************************************************************************
	> File Name: 虚函数2.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2022 05:15:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Base{
private:
    int x, y;
public:
    Base(){

    }
    virtual ~Base(){
        cout << "desrtuctor" << endl;
    }
    virtual void testInt(int n){
        cout << "call member function n = " << n << endl;
    }
    void test(){
        cout << "call member function" << endl;
    }
    static void staticfunc(){
        cout << "call static function" << endl;
    }
};

class Derived : public Base{
public:
    virtual void test(){
        cout << "call derived function" << endl;
    }
    Derived(){

    }
    ~Derived(){
        
    }
};
void func3(int n){
    cout << "call func3 n = "<< n << endl;
}
void func1(int n){
    cout << "call func1 n = "<< n << endl;
}

void func2(){
    cout << "call func2" << endl;
}

int main(){
    Base base;
    Derived derived;

    typedef void (*pClassFunc1)(void*);//类成员函数指针
    typedef void (*pClassFunc2)(void*, int);//类成员函数指针
    cout << "===============begin" << endl;
   // ((pClassFunc1**)&base)[0][1](&base);//此时报错
    ((pClassFunc1**)&base)[0][0](&base);//此时调用析构函数日志，总结：虚函数表中的虚函数，其析构函数有两块，第一块执行析构函数，第二块执行析构函数和内存的释放，两块析构的功能不一样，如果只调用第二块，由于栈空间析构释放一次内存，我们又释放一次，因此报错
    ((pClassFunc2**)&base)[0][2](&base, 123); 
    ((pClassFunc1**)&derived)[0][2](&derived);
    //首先取base类首地址，强制类型转换，此时相当于在内存划分为二维数组，一维为虚函数表的地址，二维是在虚函数表中取对应的虚函数，最后&base（传地址）是由于成员函数的参数为void*；
    cout << "================end" << endl;
    /*void (*pFunc)() = &func2;//1, 函数指针定义形式
    pFunc();//通过函数指针调用函数

    typedef void (*pFunc2)(); //2，typedef定义函数指针类型
    typedef void (*pFunc1)(int); // 同上
    pFunc1 pfunc1 = &func1;//定义函数指针变量，满足这种类型就可以进行赋值。注意取相应函数地址
    pFunc1 pfunc3 = &func3;
    pFunc2 pfunc2 = &func2;
    pfunc1(1);
    pfunc3(3);
    pfunc2();
    //1,函数指针指向成员静态方法，静态方法可以当作全局方法处理
    pFunc2 sfunc = &Base::staticfunc;
    sfunc();

    //2，函数指针指向成员非静态方法
    typedef void (Base::*pClassFunc1)();//function<void*>实际上类的成员函数，参数列表中还有void*表调用对象本身
    typedef void (Base::*pClassFunc2)(int); //function<void*, int>
    pClassFunc1 pclassfunc1 = &Base::test;//不加&，编译器会认为是在这里调用成员函数，所以需要给出参数列表，否则会报错；加了&，才认为是要获取函数指针。这是C++专门做了区别对待。
    pClassFunc2 pclassfunc2 = &Base::testInt;
    Base base;
    (base.*pclassfunc1)();//利用函数指针调用类中成员函数，为了与调用对象区别，因此加上->* /.*,括号优先级高于成员操作符指针的优先级，需要加上括号
    (base.*pclassfunc2)(123);

    //2.1不借助typedef的方式
    void (Base::*pClassFunctestVoid)() = &Base::test;
    void (Base::*pClassFunctestInt)(int) = &Base::testInt;
    (base.*pClassFunctestVoid)();
    (base.*pClassFunctestInt)(123);*/
    return 0;
}
