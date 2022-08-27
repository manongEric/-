/*************************************************************************
	> File Name: frontmid_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Apr 2022 03:08:37 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
char xian[30], zhong[30];
void func(int xl, int xr, int zl, int zr) {
    if (xl > xr) return;
    int ind; 
    char mid = xian[xl];
    for (int i = 0; i < zr; i++) {
        if (zhong[i] == mid){
            ind = i;
            break;
        }
    }
    func(xl + 1, xl + ind - zl, zl, ind - 1);
    func(xl + ind- zl + 1, xr, ind + 1, zr);
    cout << mid;
}
int main() {
    cin >> xian >> zhong;
    func(0, strlen(xian), 0, strlen(zhong));
    return 0;
}
