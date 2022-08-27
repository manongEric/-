/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Jul 2022 04:45:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class B;
class A{
public:
    int c;
};

class B{
public:
    B(){}
};

int main(){
    A a;
    cout << a.c << endl;
    return 0;
}
