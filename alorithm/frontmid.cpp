/*************************************************************************
	> File Name: frontmid.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Jan 2022 04:09:58 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

char xian[30], zhong[30];

void func(int xl,int xr, int zl, int zr) {
    cout << xl << " ";
    cout << endl;
    cout << xr << " ";
    if (xl > xr) return;
    if (xl == xr) {
        cout << xian[xl];
        return;
    }
    int ind;
    char mid = xian[xl];
    for (int i = zl; i <= zr; i++) {
        if (zhong[i] == mid) {
            ind = i;
            break;
        }
    }
        func(xl + 1, ind - zl + xl, zl, ind - 1);//左子树的先序遍历以及区间，中序遍历以及区间
        func(ind - zl + xl + 1, xr, ind + 1, zr);
        cout << mid;
}
int main() {
    cin >> xian >> zhong;
    func(0, strlen(xian), 0, strlen(zhong));
    cout << endl;
    return 0;
}

