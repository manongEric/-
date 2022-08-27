/*************************************************************************
	> File Name: oj484_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Mar 2022 04:36:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int b[130];
int main() {
    string a;
    while(cin >> a) {
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
        if(i != 'A') {
            cout << " ";
        }
        cout << (char)i;
    }
    return 0;
}
