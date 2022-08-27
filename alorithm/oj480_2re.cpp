/*************************************************************************
	> File Name: oj480_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 01:13:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
struct node {
    char s[4];
    int num1, num2, flag;
};
node m[15];
int main() {
    for (int i = 1; cin >> m[i].s; i++) {
        if (m[i].s[0] == '/') {
            m[i].num1 = 10;
            m[i].num2 = 10;
            m[i].flag = 2;
        } else if (m[i].s[1] == '/') {
            m[i].num1 = m[i].s[0] - '0';
            m[i].num2 = 10;
            m[i].flag = 1;
        } else {
            m[i].num1 = m[i].s[0] - '0';
            m[i].num2 = m[i].num1 + m[i].s[1] - '0';
            m[i].flag = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        ans += m[i].num2;
        if (m[i].flag == 1) {
            ans += m[i + 1].num1;
        } else if (m[i].flag == 2) {
            if (m[i + 1].flag == 2) {
                ans += 10 + m[i + 2].num1;
            } else {
                ans += m[i + 1].num2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
