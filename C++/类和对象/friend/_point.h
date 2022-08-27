/*************************************************************************
	> File Name: point.h
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jun 2022 07:52:10 PM CST
 ************************************************************************/

#ifndef _POINT_H
#define _POINT_H
#include "_line.h"
class Point{
    friend float Line::getDistance(const Point& p1, const Point& p2);
public :
    Point(float x, float y); 

private :
    static int count;
    float _x;
    float _y;
};
#endif
