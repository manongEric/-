/*************************************************************************
	> File Name: oj379.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 06 Mar 2022 02:33:59 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int n;
int main() {
    cin >> n;
    stack<int> mmax;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            cin >> a;
            if (i == 0) mmax.push(a);
            else mmax.push(max(mmax.top(), a));
        } else if (a == 2) {
            if (mmax.empty()) cout << 0 << endl;
            else  cout << mmax.top() << endl;
        } else {
            if (!mmax.empty()) mmax.pop();
            continue;
        }
    }


    return 0;
}

