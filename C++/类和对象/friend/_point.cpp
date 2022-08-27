/*************************************************************************
	> File Name: point.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jun 2022 07:54:01 PM CST
 ************************************************************************/

#include<iostream>
#include"_point.h"
using namespace std;
int Point::count = 123;
Point::Point(float x, float y) {
    this->_x = x;
    this->_y = y;
}
