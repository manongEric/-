/*************************************************************************
	> File Name: midback.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Jan 2022 02:43:41 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

char zhong[30], hou[30];

void func(int zl, int zr, int hl, int hr) {
    if (zl > zr) return;
    if (zl == zr) {
        cout << zhong[zl];
        return;
    }

    char mid = hou[hr];
    int ind;
    for (int i = zl; i <= zr; i++) {
        if (zhong[i] == mid) {
            ind = i;
            break;
        } 
    }
        cout << mid;
        func(zl, ind - 1, hl, ind - zl + hl - 1);
        func(ind + 1, zr, hl + ind - zl, hr - 1);
}
int main() {
    cin >> zhong >> hou;
    func(0, strlen(zhong), 0, strlen(hou));
    cout << endl;
    return 0;
}
