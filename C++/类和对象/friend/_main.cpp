/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jun 2022 08:23:20 PM CST
 ************************************************************************/

#include<iostream>
#include "_point.h"
#include "_line.h"
using namespace std;
int main() {
    Point p1(26.1f, 264.f),  p2(56.1f, 78.9f);

    Line line;
    cout << line.getDistance(p1, p2) << endl;


    return 0;
}
