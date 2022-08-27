/*************************************************************************
	> File Name: type_convert.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Aug 2022 03:23:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(test1)
template<typename T>
class remove_reference{
public:
    typedef T type;
};

template<typename T>
class remove_reference<T&& > {
public:
    typedef T type;
};

template<typename T>
class remove_reference<T& > {
public:
    typedef T type;
};
template<typename T>
class add_const{
public:
    typedef const T type;
};

template<typename T>
class add_lvalue_reference{
public:
    typedef T& type;
};

template<typename T>
class add_lvalue_reference<T&>{
public:
    typedef T& type;
};

template<typename T>
class add_lvalue_reference<T&&>{//如果没有右值偏特化  出现一个右值匹配，会优先匹配普通版本，偏特化版本更具独特性
public:
    typedef T& type;
};

template<typename T>
class remove_pointer {
public:
    typedef T type;
};

template<typename T>
class remove_pointer<T*> {
public:
    typedef typename remove_pointer<T>::type type;
};

template<typename T>
class add_pointer {
public:
    typedef T* type;
};

template<typename T>
class add_pointer<T*> {
public:
    typedef T* type;
};
int main() {
    typename remove_reference<int &>::type a;
    typename remove_reference<int &&>::type b;
    typename remove_reference<int>::type c;
    typename add_const<const int>::type d = 1;//虽然有const 但是传入模板 模板推导参数时会自动去除const
    typename add_const<int>::type e = 1;
    typename add_lvalue_reference<int>::type fa = a;
    typename add_lvalue_reference<int&>::type fb = b;
    typename add_lvalue_reference<int&&>::type fc = c;
    a = b = c = 1;
    fa = fb = fc = 2;
    cout << a << " " << b << " " << c << endl;
    return 0;
}
END(test2)

int main() {
    test1::main();

    return 0;
}
