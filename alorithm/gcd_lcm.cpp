/*************************************************************************
	> File Name: gcd_lcm.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 31 Mar 2022 10:02:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int a, b;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    while(cin >> a >> b) {
        cout << "gcd" << " : " << gcd(a, b) << endl;
        cout << "lcm" << " : " << lcm(a, b) << endl;
    }
}
