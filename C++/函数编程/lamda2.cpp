/*************************************************************************
	> File Name: lamda2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Jul 2022 10:08:38 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;


auto ADD = [](int a, int b) {
    return a + b;
};

auto SUB = [](int a, int b) {
    return a - b;
};

auto MAX = [](int a, int b) {
    return a > b ? a : b;
};
auto MIN = [](int a, int b) {
    return a < b ? a : b; 
};
auto Data2 = [](int a, int b) {
    return [=](function<int(int, int)> func) {//只能用值传递，因为a, b是临时变量，会释放内存
        return func(a, b);
    };
};
struct Data{
private:
    int a, b;
public:
    Data(int m, int n):a(m), b(n) {

    }
    int operator()(function<int(int, int)> func) {
        return func(a, b);
    }
};
int main() {
    auto data = Data2(1, 2);
    cout << "data(ADD) = " << data(ADD) << endl;
    cout << "data(SUB) = " << data(SUB) << endl;
    cout << "data(MAX) = " << data(MAX) << endl;
    cout << "data(MIN) = " << data(MIN) << endl;

    return 0;
}


