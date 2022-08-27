/*************************************************************************
	> File Name: print.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Jul 2022 03:03:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Point {
    //friend void print(const Point&, int);
    //friend void print(const Point&, float);
    friend ostream& operator<<(ostream&,const Point&);
private:
    float _x, _y;
public:
    Point(float x): _x(x), _y(x) {

    }
    Point(float x, float y):_x(x), _y(y) {
        
    }
    Point(const Point& p):_x(p._x),_y(p._y) {

    }
    void print(int){
        cout << "x = " << (int)_x << " y = " << (int)_y << endl;
    }
    void print(float) {
        cout << "x = " << _x << " y = " << _y << endl;
    }

    Point operator+(const Point& p) {//返回值为一个临时变量
       // Point ans(p);//对象就是一个值  只有是地址时才*取值
        Point ans(*this);
        ans._x += p._x;
        ans._y += p._y;
        return ans;
    }
    Point operator++(int) {//只是为了告诉编译器,这是一个后++，区分函数重载
        Point ans(*this);
        this->_x++;
        this->_y++;
        return ans;
    }
    Point& operator++(){
        this->_x++;
        this->_y++;
        return *this;
    }
    float operator*(const Point& p) {
        return this->_x * p._x + this->_y * p._y;
    }
};
/*void print(const Point& p, int) {//外部函数也可以作成员函数重载，但是重复了，没有必要, 成员函数可以直接重载
    cout << "x = " << (int)p._x << " y = " << (int)p._y << endl;
}
void print(const Point& p, float) {
    cout << "x = " <<p. _x << " y = " <<p. _y << endl;
}*/
void print(void* n) {
    cout << "point type" << endl;
}
/*void print(int n) {
    cout << "int type" << endl;
}*/
ostream& operator<<(ostream &os, const Point& p) {//第一个参数是调用操作符的对象，第二个是要打印的对象
    os << "x = " << p._x << " y = " << p._y;
    return os;
}
void print(int n, int m = 0, int k = 0) {//新增接口，新增了参数，可供更多选择，首先把新增参数赋予默认值
    if (m == 0 && k == 0) // 旧逻辑
    cout << "int type" << endl; 
    else {}//新逻辑
}
void print(float n) {
    cout << "float type" << endl;
}
int main() {
    print((float)1.0);// 只看1.0是double， 先精确匹配，匹配不上再隐式转换，double转换为int和float都有可能

    print(nullptr);
    print(1);
    print(1.0f);

    Point p1(1.02f, 2.45f), p2(5.32f, 7.26f);
    cout << p1 + p2 << endl;
    cout << p1++ << endl;
    cout << ++p1 << endl;
    cout << p1 * p2 << endl;
    cout <<"========================" << endl;

    p1.print(1);
    p1.print(1.0f);
 
    //print(p1, 1);
   // print(p1, 1.0f);

    return 0;
}
