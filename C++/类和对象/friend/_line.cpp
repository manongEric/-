/*************************************************************************
	> File Name: line.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jun 2022 07:58:11 PM CST
 ************************************************************************/

#include "_line.h"
#include "_point.h"
#include<cmath>
float Line::getDistance(const Point& a, const Point& b) {
    return sqrt((a._x - b._x) * (a._x - b._x) + (a._y - b._y) * (a._y - b._y));
}
