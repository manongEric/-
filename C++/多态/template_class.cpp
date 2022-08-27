/*************************************************************************
	> File Name: template_class.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2022 03:41:43 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

namespace Eric{
    template<class T>
    class print{
    public:
        print(){}
        print(int n){}
        template<class U>//类函数模板函数
        print& operator()(U u){//小括号重载
            cout << u << " ";
            return *this;//不停调用仿函数
        }
        
        print& operator()(const char* p){
            if(strcmp("endl", p) == 0)
                cout << endl;
            else 
                cout << p;
        }
    };
};

int main(){
    //方式一：先创建对象，再调用仿函数
   // Eric::print<void> print;
   // print(1)("kkb")(1.3f);
    //方式二：直接构造
    Eric::print<void>(1)(2.4)("endl")("kkb")(1.3f);
    return 0;
}
