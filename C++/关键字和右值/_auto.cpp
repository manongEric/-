/*************************************************************************
	> File Name: auto.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2022 09:45:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    int x, y;
public:
   // A() = default;
    constexpr A():x(0), y(0){

    }
    constexpr int test() const{//constexpr函数返回值，在编译器是不能变的，const， 该函数不会修改任何数据成员
        return x;
    }
};

int main(){
    auto n = 1;//auto:根据右值推导n的类型
    const A a;


    return 0;
}
