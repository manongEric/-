/*************************************************************************
	> File Name: lesson3-moveCon.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2022 07:14:39 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
class A{
private:
    char* _data;
public:
    A(const char* p){
        int size = strlen(p) + 1;
        _data = (char*)malloc(size);
        strncpy(_data, p, size - 1);
        _data[size - 1] = '\0';//拷贝后下标是从0开始的
    }
    A(const A& a){
        cout << "copy constructor" << endl;
        int size = strlen(a._data) + 1;
        _data = (char*)malloc(size);
        strncpy(_data, a._data, size - 1);
        _data[size - 1] = '\0';//拷贝后下标是从0开始的
    }
    A(A&& a):_data(a._data){//利用右值，移动构造，a对象成员使用完即舍弃释放，记得置为空，相比拷贝构造更简单
        a._data = nullptr;
        cout << "move constructor" << endl;
    }
    virtual ~A(){
        delete _data;
    }
    void test(){
        cout << _data << endl;
    }
};

int main(){
    A a("abcdefg");
    a.test();
    
    //A b(a);
    A c(move(a));
    return 0;
}
