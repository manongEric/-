/*************************************************************************
	> File Name: deep_copy.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Jun 2022 03:57:28 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

class Point{
private:
    float _x, _y;
public:
    Point(float x, float y): _x(x), _y(y){

    }
    Point(const Point& p):_x(p._x), _y(p._y){//拷贝构造
        
    }
};

class Line {
private:
    Point *start;
    Point *end;
public:
    Line ():start(nullptr), end(nullptr) {

    }
    Line(const Point& p1, const Point& p2)
    :start(new Point(p1)), end(new Point(p2)) {//拷贝Point类的拷贝构造函数
        
    }
   /* Line(const Line& line): start(line.start), end(line.end) {//关于自身的浅拷贝构造函数
        
    }*/
    Line(const Line& line): start(new Point(*line.start)), end(new Point(*line.end)) {
    //关于自身的深拷贝
    }
    void operator=(const Line& line) {//深拷贝赋值重载,拷贝赋值函数
        if (line.start) {
            if (start) {
                memcpy(start, line.start, sizeof(Point));
            } else {
                start = new Point(*line.start);
            }
        } else {
            if (start) delete start;
            start = nullptr;
        }
        if (line.end) {
            if (end) {
                memcpy(end, line.end, sizeof(Point));
            } else {
                end = new Point(*line.end);
            }
        } else {
            if (end) delete end;
            end = nullptr;
        }
    }
    ~Line() {//在构造函数中有new对象,析构中要delete
        delete start;
        delete end;
    }
};

int main() {
    Point *p1 = new Point(1.0f, 3.0f);
    Point *p2 = new Point(2.0f, 4.0f);
    Line *line1 = new Line(*p1, *p2);
    Line *line2 = new Line(*line1);
    Line line3;
    line3 = *line1;
    delete line2;
    delete line1;
    delete p2;
    delete p1;
    return 0;
}
