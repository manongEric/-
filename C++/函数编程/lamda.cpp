/*************************************************************************
	> File Name: lamda.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Jul 2022 04:05:54 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<functional>
using namespace std;

struct Print{
    static void print(int n) {
        cout << "class static print ----n = " << n << endl;
    }
    void print2(const vector<int>& arr, function<void(int)> func) {
        //cout << "class member print ----n = " << n << endl;
        for (auto it : arr) {
            func(it);
        }
    }
};

void helloworld() {
    cout << "hello world " << endl;
}

int main() {
    cout << "===auto定义函数指针调用类外函数===" << endl;
    auto func = helloworld;
    func();

    cout << "===auto定义函数指针调用类函数===" << endl;
    auto ap1 = &Print::print;
    ap1(123);
    Print obj;
    //auto ap2 = &Print::print2;
    //非auto调用方式  void (Print::*ap2)(int) = &Print::print2;
    //(obj.*ap2)(123);//非静态必须要以对象调用的方式

    cout << "====lamda表达式===" << endl;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    int m = 3;
    obj.print2(arr, [m](int n)mutable{//表示函数对象内部数据可变 {//lamda表达式看成函数对象，传递给调用函数
        m++;//m不属于lamda函数对象内部变量，每一次进入时，会发生+1, m属于父作用域，生命周期是for循环完全结束才会释放；
        int mm = 1;//mm属于函数内部变量，因此每一次进入，会还原，不会一直加1, 每一次进入lamda表达式,系统都会给mm分配内存空间，mm的生命周期是lamda表达式结束
        mm++;
        cout << "print with lamda = n * 2  " << n * 2 << endl;
    });
    cout << "end m = " <<  m << endl;
    return 0;
}
