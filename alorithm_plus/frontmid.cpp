/*************************************************************************
	> File Name: frontmid.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Mar 2022 05:03:48 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
char xian[30], zhong[30];
void func(int xl, int xr, int zl, int zr) {
    if (zl > zr) return;
   /* if (xl == xr) {
        cout << xian[xl];
        return;
    }*/
    char mid = xian[xl];
    int ind;
    for (int i = zl; i <= zr; i++) {
        if (zhong[i] == mid) {
            ind = i;
            break;
        }
    }
    func(xl + 1, ind - zl + xl, zl, ind - 1);
    func(ind -zl + xl + 1, xr, ind + 1, zr);
    cout << mid;
}
int main() {
    cin >> xian >> zhong;
    func(0, strlen(xian), 0, strlen(zhong));
    cout << endl;
    return 0;
}

