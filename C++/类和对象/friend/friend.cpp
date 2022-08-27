/*************************************************************************
	> File Name: friend.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jun 2022 07:10:45 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

class Point;
class Line{
public :
    float getDistance(const Point& a, const Point& b);

};
class Point{
    friend float getDistance(const Point& a, const Point& b) {//外部函数不能访问私有成员

        return sqrt((a._x - b._x) * (a._x - b._x) + (a._y - b._y) * (a._y - b._y));
    }
    friend class Line;
public :
    Point(float x, float y) {
        this->_x = x;
        this->_y = y;
    }

private : 
    float _x;
    float _y;
};

float Line ::getDistance(const Point& a, const Point& b) {
    return sqrt((a._x - b._x) * (a._x - b._x) + (a._y - b._y) * (a._y - b._y));
}
int main() {
    Point p1(1.2f, 26.5f), p2(2.0f, 15.4f);
    cout << getDistance(p1, p2) << endl;
    Line line;
    cout << "Line :" << line.getDistance(p1, p2) << endl; 
    return 0;
}
