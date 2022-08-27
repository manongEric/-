/*************************************************************************
	> File Name: trails.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Jul 2022 07:37:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<class T>
void test(const T& t){
    cout << "left is_array = " << is_array<T>::value << endl;
    cout << "left is_pointer = " << is_pointer<T>::value << endl;
    cout << "left is_rvalue_reference = " << is_rvalue_reference<decltype(t)>::value << endl;

    using TYPE = typename remove_pointer<T>::type; //模板推导类型用typename修饰，编译器可能认为是变量
    cout << "is_same int = " << is_same<int, TYPE>::value << endl;
    cout << "is_same int[] = " << is_same<int[3], TYPE>::value << endl;

    //TD<TYPE> object// 类或结构体的前向声明只能用来定义指针对象或引用，因为编译到这里时还没有发现定义，不知道该类或者结构的内部成员，没有办法具体的构造一个对象，所以会报错。
    //
}
template<class T> 
void test(const T&& t){
    cout << "right is_array = " << is_array<T>::value << endl;
    cout << "right is_pointer = " << is_pointer<T>::value << endl;
    cout << "right is_rvalue_reference = " << is_rvalue_reference<decltype(t)>::value << endl;
}

int main(){
    int a[] = {1, 2, 3};
    int *b = a;
    test(a);
    test(b);

    test(123);
    return 0;
}
