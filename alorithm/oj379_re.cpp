/*************************************************************************
	> File Name: oj379_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 06:29:11 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
stack<int> mmax;
int n;
int main() {
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a == 0) {
            int b;
            cin >> b;
            if (mmax.empty()) mmax.push(b);
            else mmax.push(max(mmax.top(), b));
        } else if (a == 1) {
            if (!mmax.empty()) mmax.pop();
        } else {
            if (mmax.empty()) {
                cout << 0 << endl;
            } else {
                cout << mmax.top() << endl;
            }
        }
    }
    return 0;
}
