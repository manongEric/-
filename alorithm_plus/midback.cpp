/*************************************************************************
	> File Name: midback.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Mar 2022 07:14:02 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
char zhong[30], hou[30];
void func(int zl, int zr, int hl, int hr) {
    if (zl > zr) return;
    int ind;
    char mid = hou[hr];
    for (int i = zl; i <= zr; i++) {
        if (zhong[i] == mid) {
            ind = i;
            break;
        }
    }
    cout << mid;
    func(zl, ind - 1, hl, ind - zl - 1 + hl);
    func(ind + 1, zr, ind - zl + hl, hr - 1);
}
int main() {
    cin >> zhong >> hou;
    func(0, strlen(zhong), 0, strlen(hou));
    return 0;
}
