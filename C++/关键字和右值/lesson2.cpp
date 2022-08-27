/*************************************************************************
	> File Name: lesson2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2022 03:50:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void print(int& n) {
    cout << __PRETTY_FUNCTION__ << endl;
}
void print(int&& n) {
    cout << __PRETTY_FUNCTION__ << endl;
}
void print(const int& n) {
    cout << __PRETTY_FUNCTION__ << endl;
}
void print(const int&& n) {
    cout << __PRETTY_FUNCTION__ << endl;
}


void func(int& n){
    cout << "left value" << endl;
    print(forward<int&>(n));//完美转化
}
void func(int&& n){
    cout << "right value" << endl;
    print(forward<int&&>(n));
}
void func(const int& n){
    cout << "left value" << endl;
    print(n);
  //  print(forward<const int& n>(n));
}
void func(const int&& n){
    cout << "right value" << endl;
    print(n);
    //print(forward<const int&& n>(n));
}

int main(){
    int a = 1;
    int& b = a;
    const int c = 2;
    const int& d = a;

    int&& e = 9;
    const int&& f = 2;//已命名的右值引用，编译器会认为是左值
/*
    print(a);//int& n 左值引用
    print(b);//int&
    print(c);//const int&
    print(d);//const int&
    print(2);//没有任何一个对象或者指针指向2，无法修改，这个值就是右值
*/
    func(b);
    func(2);
    func(move(e));//转换为右值
    func(move(f));
    cout << "==============" << endl;
    int x, y;
    x + y;
    x++;
    ++x;
    print(x + y);//lvalue 临时变量， 可以修改
    print(x++);//lvalue 临时变量
    print(++x);//rvalue ： 引用， 无法修改
    return 0;
}
