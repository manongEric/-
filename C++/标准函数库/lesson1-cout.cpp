/*************************************************************************
	> File Name: lesson1-cout.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Jul 2022 05:15:21 PM CST
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cout << setiosflags(ios::left);//左对齐
    cout.precision(6);//总共保留多少位
    cout << 123.46789 << endl;

    cout.width(20);
    cout.fill('*');//对空格填充
    cout << 123.46789 << endl;//修饰后，对后一次输出有效

    
    cout << setiosflags(ios::right);//右对齐
    cout.width(20);
    cout.fill('*');
    cout << 123.46789 << endl;
    
    cout << "保留三位小数 : " << fixed << setprecision(3) << 123.46789 << endl;
    return 0;
}

