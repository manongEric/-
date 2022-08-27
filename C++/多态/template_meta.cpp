/*************************************************************************
	> File Name: template_meta.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2022 05:01:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<int m, int n>
struct Meta_Sum {
    static const int value = m + n;//static必须初始化
};

template<int m> 
struct My_Sum{
    static constexpr int value = m + My_Sum<m - 1>::value;
};
template<>
struct My_Sum<1>{
    static constexpr int value = 1;
};


template<int code>
struct meta_Area{
    static constexpr auto value = "zhongguo";//""内是一个右值常量，字面量，将亡值，我们用一个指针指向它，加入被释放会有风险，因此warning
};
template<>
struct meta_Area<10>{
    static constexpr auto value = "beijing";
};
template<>
struct meta_Area<21>{
    static constexpr auto value = "shanghai";
};
template<>
struct meta_Area<571>{
    static constexpr auto value = "hangzhou";
};

template<bool b, class IF, class ELSE>
struct IFELSE{
    using type = IF;//别名 ， typedef void type
};

/*template<class IF, class ELSE>
struct IFELSE<true, IF, ELSE> {
    using type = IF;
};*/

template<class IF, class ELSE>
struct IFELSE<false, IF, ELSE> {
    using type = ELSE;
};

template<int n, class T, class ...args>
struct ARG {
    using type = typename ARG<n - 1, args...>::type;
};

template<class T, class ...args>
struct ARG<0, T, args...>{//特化参数不带类型
    using type = T;
};
int main() {
    cout << "========元数据=======" << endl;
    cout << Meta_Sum<100, 200>::value << endl;//编译时就确定好结果，元编程
    cout << My_Sum<100>::value << endl;
    cout << "========元编程实现switch分支=======" << endl;
    cout << meta_Area<10>::value << endl;
    cout << meta_Area<21>::value << endl;
    cout << meta_Area<571>::value << endl;
    cout << meta_Area<100>::value << endl;
    cout << "=========IFELSE========" << endl;
    IFELSE<true, int, double>::type a;
    IFELSE<false, int, double>::type b;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    std::conditional<true, int, double>::type aa;
    std::conditional<false, int, double>::type bb;
    cout << typeid(aa).name() << endl;
    cout << typeid(bb).name() << endl;

    cout << "==========不定参=======" << endl;
    ARG<0, int, double, float, char, long>::type a1;
    ARG<1, int, double, float, char, long>::type a2;
    ARG<2, int, double, float, char, long>::type a3;
    ARG<3, int, double, float, char, long>::type a4;
    ARG<4, int, double, float, char, long>::type a5;
    cout << "a1 " << typeid(a1).name() << endl;
    cout << "a2 " << typeid(a2).name() << endl;
    cout << "a3 " << typeid(a3).name() << endl;
    cout << "a4 " << typeid(a4).name() << endl;
    cout << "a5 " << typeid(a5).name() << endl;
    return 0;
}
