/*************************************************************************
	> File Name: template.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Jul 2022 03:03:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Point{
public:
    int operator+(const Point& p) {
        return 123;
    }
};
template<class T, class U>
auto add(T a, U b)->decltype(a + b) {//用auto推导类型，返回值后置手段
    T();
    cout << "common template" << endl;
    return a + b;
}

template<class T>
T add(T a, float b) {
    cout << "special template" << endl;
    return a + b;
}

template<>//全特化模板，优先匹配 add(1, 2);
int add(int a, int b){
    cout << "all special template" << endl;
    return a + b;
}
/*int add(int a, int b) {//float 可以转换为Int
    cout << "common function" << endl;
    return a + b;
}*/


int main() {
    add<int>(1, 1.2f);//两个参数类型不一样，无法调用模板，只能显示调用，这时参数若能根据类型隐式转换，则调用模板,或者特化
    cout << add<int>(1, 2) << endl; //显示调用模板

    //cout << add(1, 2) << endl;//默认调用函数
   // cout << add(1.3f, 3.2f) << endl;
    
    cout << "==================模板出现的不确定性" << endl;
    cout << "add(1.2f, 2) = " << add(1.2f, 2) << endl;//T->float
    cout << "add(2, 1.2f) = " << add(2, 1.2f) << endl;//T->int

    //解决方法，模板函数多一个参数
    cout << "add(2, 1.2f) = " << add<float, float>(2, 1.2f) << endl;//T->int
    cout << "==================decltype" << endl;
    cout << "==================推导类型函数模板" << endl;
    Point p1, p2;
    decltype(p1 + p2) p = p1 + p2;
    cout <<"typeid(p).name() = "<< typeid(p).name() << " p = " << p << endl;
    return 0;
}
