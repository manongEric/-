/*************************************************************************
	> File Name: oj377.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Mar 2022 07:56:29 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
char s[305];
int main() {
    stack<char> sta;
    cin >> s;
    for (int i = 0; s[i] != '@'; i++) {
        if (s[i] == '(') {
            sta.push(s[i]);
        }else if (s[i] == ')') {
            if (sta.empty()) {
                cout << "NO" << endl;
                return 0;
            }else {
                sta.pop();
            }
        }
    }
    if (!sta.empty()) {
        cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
    }
    return 0;
}

