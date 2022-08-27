/*************************************************************************
	> File Name: args_template.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Aug 2022 04:15:38 PM CST
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(test1)
//1 设计能够解析模板变参列表类型的工具模板
//2变参列表有且只有两个参数，否则报编译时的错误
template<int N, typename T, typename ...ARGS>//N代表我们要获得第几个参数类型
class GetType{
public:
    typedef typename GetType<N - 1, ARGS...>::type type;//要获得第N个参数即ARGS中的N-1个
};


template<typename T, typename ...ARGS>
class GetType<1, T, ARGS...>{
public:
    typedef T type;
};

template<typename T>//这种情况时没有可变参数列表，这时直接取的就是第一个T参数
class GetType<1, T>{
public:
    typedef T type;
};
template<typename T, typename ...ARGS>
class CountTypeNums{
public:
    constexpr static const int r = CountTypeNums<ARGS...>::r + 1;
};

template<typename T> 
class CountTypeNums <T>{
public:
    constexpr static const int r = 1;
};

template<int N>
class Zero{
public:
    typedef int no;
};

template<>
class Zero<0> {
public:
    typedef int ok;
};
template<int N, typename ...ARGS>
class JudgeTypeNums {
public:
    typedef typename Zero<CountTypeNums<ARGS...>::r-2>::ok ok;
};
template<typename T, typename ...ARGS> 
class func{
public:
    typedef typename JudgeTypeNums<2, ARGS...>::ok has2_type;
    T operator()(typename GetType<1, ARGS...>::type a, typename GetType<2, ARGS...>::type b) {
        return a + b;
    }

};

int main() {
    func<int, int, int> f;
    cout << f(3, 4) << endl;
    return 0;
}

END(test1)

BEGIN(test2)
//实现判断素数的模板类
#define judge_even(x) (is_even<x>::r(#x))
#define judge_prime(x) (is_prime<x>::r(#x))
#define calc_sum(x) (template_sum<x>::r(x, #x))
class condition {
public:
    condition(string msg) : msg(msg) {}
    string msg;
};
class is_prime_condition : public condition {
public:
    is_prime_condition(string msg): condition(msg + " is prime") {}
};
class is_not_prime_condition : public condition {
public:
    is_not_prime_condition(string msg): condition(msg + " is not prime"){}
};
class is_even_condition : public condition {
public:
    is_even_condition(string msg) : condition(msg + " is even"){}
};

class is_not_even_condition : public condition {
public:
    is_not_even_condition(string msg) : condition(msg + " is not even"){}
};
ostream &operator<<(ostream& out, const condition& obj) {
    out << obj.msg;
    return out;
}

template<int N, int i>
class getNextN {
public:
    constexpr static const int r = (N % i || i >= N ? N : 0);
};

template<int N, int i>
class getNextI {
public:
    constexpr static const int r = (i * i > N ? 0 : i + 1);
};
template<int N, int i>
class is_prime_test{
public:
    typedef typename is_prime_test<getNextN<N, i>::r, getNextI<N, i>::r>::r r;
};

template<int N>
class is_prime_test<N, 0> {
public:
    typedef is_prime_condition r;
};

template<int i>
class is_prime_test<0, i> {
public:
    typedef is_not_prime_condition r;
};
template<int N>
class is_prime {
public:
    typedef typename is_prime_test<N, 2>::r r;
};

template<int N>
class is_even_test{
public:
    typedef is_not_even_condition r;
};
template<>
class is_even_test<0>{
public:
    typedef is_even_condition r;
};

template<int N>
class is_even {
public:
    typedef typename is_even_test<N % 2>::r r;
};

class calc_sum_class : public condition {
public:
    calc_sum_class(int x, string msg) : 
    condition(string("add from 1 to ") + msg + string(" is ")) {
        stringstream ss;//sstream> 主要用来进行数据类型转换, int -> string
        string ans;
        ss << (x * (x + 1) / 2);
        ss >> ans;
        this->msg = ans;
    }
};

template<int N>
class template_sum {
public:
    typedef calc_sum_class r;
};
int main() {
    cout << judge_prime(2) << endl;
    cout << judge_prime(5) << endl;
    cout << judge_prime(13) << endl;
    cout << judge_prime(100) << endl;

    cout << judge_even(2) << endl;
    cout << judge_even(3) << endl;

    cout << calc_sum(100) << endl;
    cout << calc_sum(10) << endl;
    return 0;
}

END(test2)

BEGIN(test3)
template<int N, int i>
class getNextN {
public:
    constexpr static const int r = (N % i || i >= N ? N : 0);
};

template<int N, int i>
class getNextI {
public:
    constexpr static const int r = (i * i > N ? 0 : i + 1);
};
template<int N, int i>
class is_prime_test{
public:
    constexpr static const int r = is_prime_test<getNextN<N, i>::r, getNextI<N, i>::r>::r;
};

template<int N>
class is_prime_test<N, 0> {
public:
    constexpr static const int r = 1;
};

template<int i>
class is_prime_test<0, i> {
public:
    constexpr static const int r = 0;
};
template<int N>
class is_prime {
public:
    constexpr static const int r =  is_prime_test<N, 2>::r;
};

template<int N>
class prime_sum {
public:
    constexpr static const int r = N * is_prime<N>::r + prime_sum<N - 1>::r ;
};

template<>
class prime_sum<1> {
public:
    constexpr static const int r = 0;
};
#define calc_prime_sum(x) " within " << x << " is " << prime_sum<x>::r
int main() {
    cout << calc_prime_sum(10) << endl;
    cout << calc_prime_sum(100) << endl;

    return 0;
}

END(test3)
int main() {
    test3::main();
    return 0;
}
