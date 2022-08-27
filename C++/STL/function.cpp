/*************************************************************************
	> File Name: function.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Jul 2022 11:10:11 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

int add(int a, int b) {
    return a + b;
}

struct functor {
    functor():value(999) {

    }
    int operator()(int a, int b) {
        return a + b;
    }
    int add(int a, int b) {
        return a + b;
    }

    static int ADD(int a, int b) {
        return a + b;
    }

    int value;
};

int main() {
    functor obj;
    function<int(int, int)> f1 = &add;
    cout << "普通函数 : " << f1(123,456) << endl;

    function<int(int, int)> f2 = functor();
    cout << "仿函数 ： " << f2(123, 456) << endl;

    function<int(functor*, int, int)> f3 = &functor::add;
    cout << "class member function = " << f3(&obj, 123, 456) << endl;

    function<int(int, int)> f4 = &functor::ADD;
    cout << "class static function = " << f4(123, 456) << endl;

    function<int(int, int)> f5 = [](int a, int b){return a + b;};
    cout << "lamda function = " << f4(123, 456) << endl;
    
    function<int(functor*)> f6 = &functor::value;
    cout << "class member value = " << f6(&obj) <<endl;
    return 0;
}
