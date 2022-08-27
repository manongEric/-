/*************************************************************************
	> File Name: template_plus.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Jul 2022 05:43:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

namespace Eric{
    class Point{
    private:
        float _x, _y;
    public:
        Point() = delete;
        Point(const Point& p):_x(p._x), _y(p._y){
            
        }
        Point(float x, float y):_x(x), _y(y){

        }
        void operator=(Point& p) {
            _x = p._x;
            _y = p._y;
        }
    };
    template<class T>
    void swap(T& a, T& b){
        /*方式1， 如果默认构造没有， 可以使用malloc开辟内存，然后用memcpy拷贝
        T* c = (T* )malloc(sizeof(T));
        memcpy(c, &a);
        */
        //方式二：存在默认构造，调用拷贝构造
        T c = a;
        a = b;
        b = c;
    }
    template<class T>
    void swap(T&& a, T&& b){//这里均可以定义为&&(universe reference),在模板中，&&可以匹配左右值
        typename std::remove_reference<T>::type c = a;//针对swap(a, b)都是左值引用的情况，如果不调用去掉模板引用函数，那么根据引用坍塌，T类型就是一个左值引用类型，T c = a会导致c总是和a的地址绑定，无法正确交换a，b变量的值
        //T c = a;
        a = b;
        b = c;
    }
}

int main() {
    int a = 123, b = 456;
    Eric::swap(a, b);
    cout << a << " " << b << endl;
    cout << "======交换类对象======" << endl;
    Eric::Point p1(1.1f,2.3f), p2(23.4f,3.3f);
    Eric::swap(p1, p2);
    cout << "======交换常量,左右值======" << endl;
    //引用坍塌规则：对引用进行引用时，函数形参T & & 不一定能进行右值引用，当传入的是左值时，会被推导为左值。也就是说只有传入右值引用才是真的右值引用
    Eric::swap(move(a), 999);//T->int -> int&&(引用坍塌)->int&&
    Eric::swap(a, b);//T->int&->int&&&(引用坍塌)->int&
    cout << "a = " << a << endl;
    
    
}
