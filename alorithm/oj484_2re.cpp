/*************************************************************************
	> File Name: oj484_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 02:08:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int b[130];
int main() {
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            b[s[i]]++;
        }
    }
    int mmax = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        mmax = max(b[i], mmax);
    }
    for (int i = 0; i < mmax; i++) {
        int last = -1;
        for (int j = 'Z'; j >= 'A'; j--) {
            if (b[j] >= mmax - i) {
                last = j;
                break;
            }
        }
        for (int j = 'A'; j <= last; j++) {
            if (b[j] >= mmax - i) {
                cout << "*";
            } else {
                cout << " ";
            }
            if (j != last) cout << " ";
        }
        cout << endl;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        if (i != 'A') cout << " ";
        cout << (char)i;
    }
    cout << endl;
    return 0;
}
