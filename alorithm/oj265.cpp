/*************************************************************************
	> File Name: oj265.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Apr 2022 11:13:07 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int ans;
stack<char> s1;
stack<int> s2;
void cle(int x){
    while(!s1.empty()) {
        s1.pop();
        s2.pop();
    }
    s1.push('#');
    s2.push(x);
} 
int main() {
    s1.push('#');
    s2.push(-1);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            s1.push(s[i]);
            s2.push(i);
        } else if (s[i] == ')') {
            if (s1.top() == '('){
                s1.pop();
                s2.pop();
                ans = max(ans, i - s2.top());
            }else {
                cle(i);
            }
        } else if (s[i] == ']') {
            if (s1.top() == '['){
                s1.pop();
                s2.pop();
                ans = max(ans, i - s2.top());
            }else {
                cle(i);
            }
        } else if (s[i] == '}') {
            if (s1.top() == '{'){
                s1.pop();
                s2.pop();
                ans = max(ans, i - s2.top());
            }else {
                cle(i);
            }
        }

    }
    cout << ans << endl;
    return 0;
}
