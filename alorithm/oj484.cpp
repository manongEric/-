/*************************************************************************
	> File Name: oj484.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Mar 2022 08:46:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int b[130];
int main() {
    string a;
    while (cin >> a) {
        for (int i = 0; i < a.size(); i++) {
            b[a[i]]++;
        }
    }
    int mmax = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        mmax = max(mmax, b[i]);
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
            }else {
                cout << " ";
            }
            if (j != last) {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 'A'; i <= 'Z'; i++) {
        if (i != 'A') {
            cout << " ";
        }
        cout << (char)i;
    }
    cout << endl;
    return 0;
}
