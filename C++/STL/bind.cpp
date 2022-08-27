/*************************************************************************
	> File Name: bind.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Jul 2022 11:38:11 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
int add(int a, int b) {
    cout << "a = " << a << " b = " << b << endl;
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
void testRef(int &n){
    n++;
}

int main() {
    //两个参数转换为0个参数
    function<int()> f1 = bind(add, 123, 456);
    cout << f1() << endl;
    
    //两个参数转换为1个参数
    function<int(int)> f2 = bind(add, 123, std::placeholders::_1);
    cout << f2(456) << endl;

    //排列参数顺序
    function<int(int, int)> f3 = bind(add, std::placeholders::_2, std::placeholders::_1);
    cout << f3(123, 456) << endl;
    function<int(int, int)> f4 = bind(add, std::placeholders::_1, std::placeholders::_2);
    cout << f3(123, 456) << endl;
   
    functor f;
    function<int(int, int)> f5 = bind(&functor::add, &f, std::placeholders::_1, std::placeholders::_2);
    cout << "bind class member function " << f5(123, 456) << endl;
    
    function<int(int, int)> f6 = bind(&functor::operator(), &f, std::placeholders::_1, std::placeholders::_2);
    cout << "bind  functor1 " << f6(123, 456) << endl;

    function<int(int, int)> f7 = bind(f, std::placeholders::_1, std::placeholders::_2);
    cout << "bind  functor2 " << f7(123, 456) << endl;
    int m = 1;
    function<void()> func = bind(testRef, std::ref(m));//stdbind使用的是参数的拷贝而不是引用，当可调用对象期待入参为引用时，必须显示利用std::ref来进行引用绑定。
    func();
    func();
    cout << "m = " << m << endl;

    //moudulus取模，less表达式，与count_if的结合
    int a[] = {1, 2, 3, 4, 5 ,6 ,7 ,8 ,9};
    int count = count_if(a, a + 9, bind2nd(modulus<int>(), 2));//count_if要求第三个参数是一元函数，而moudulus是二元函数，因此用bind2nd进行转换
    cout << "count = " << count << endl;

    cout << ">3 = " << count_if(a, a + 9, bind1st(less<int>(), 3)) << endl;
    cout << "<3 = " << count_if(a, a + 9, bind2nd(less<int>(), 3)) << endl;
    return 0;
}
