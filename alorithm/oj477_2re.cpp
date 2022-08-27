/*************************************************************************
	> File Name: oj477_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 12:39:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int last = 0, mmax = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'O'|| s[i] == 'I' || s[i] == 'U') {
            mmax = max(mmax, i - last);
            last = i;
        }
    }
    cout << mmax << endl;;
    return 0;
}
