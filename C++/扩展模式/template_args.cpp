/*************************************************************************
	> File Name: template_args.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Jul 2022 11:37:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(test1)
class A{
public:
    A():x(12), y(13){}
    int x, y;
};
template<typename T>
void print(T a) {
    cout << a << endl;
    return;
}
template<typename T, typename ...ARGS>
void print(T a, ARGS ...args) {
    cout << a << endl;
    print(args...);
}

ostream& operator<<(ostream& out, const A &a){
    cout << "(" << a.x << ", " << a.y << ")";
    return out;
}
int main() {
    A a;
    print("hello, world", 123, 12.3);
    print(123, 12.3, a, 8.9f);
    return 0;
}


END(test1)

//利用模板特化偏特化判断某个类型是否有构造函数
BEGIN(test2)
class yes_condition{
public:
    yes_condition(const char* msg = ""):msg(msg){

    }
    const char* msg;
};
class no_condition{
public:
    no_condition(const char* msg = ""):msg(msg){

    }
    const char* msg;
};

ostream &operator<<(ostream &out, const yes_condition& obj){
    out << obj.msg << ":" << "yes";
    return out;
}

ostream &operator<<(ostream &out, const no_condition& obj){
    out << obj.msg << ":" << "no";
    return out;
}
template<typename T>
class type_trais{
public:
    typedef yes_condition has_constructor;
};

template<typename T>
class type_trais<T*> {
public:
    typedef no_condition has_constructor;
};

template<>
class type_trais<int> {
public:
    typedef no_condition has_constructor;
};

template<>
class type_trais<double> {
public:
    typedef no_condition has_constructor;
};
template<>
class type_trais<float> {
public:
    typedef no_condition has_constructor;
};
class A{};

#define HAS_CONSTRUCTOR(__type) type_trais<__type>::has_constructor(#__type)
int main() {
    /*cout << type_trais<int>::has_constructor() << endl;
    cout << type_trais<double>::has_constructor() << endl;
    cout << type_trais<string>::has_constructor() << endl;
    cout << type_trais<A* >::has_constructor() << endl;
    cout << type_trais<A>::has_constructor() << endl;
    cout << type_trais<int *>::has_constructor() << endl;*/

    cout << HAS_CONSTRUCTOR(int) << endl;
    cout << HAS_CONSTRUCTOR(double) << endl;
    cout << HAS_CONSTRUCTOR(string) << endl;
    cout << HAS_CONSTRUCTOR(A*) << endl;
    cout << HAS_CONSTRUCTOR(int*) << endl;
    return 0;
}


END(test2)
int main() {
    //test1::main();
    test2::main();

    return 0;
}
