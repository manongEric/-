/*************************************************************************
	> File Name: oj504_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 02:46:57 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int n;
int main() {
    string s;
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ind = s.size() - 1;
        for (int j = 1; j < s.size(); j++) {
            if (s[j - 1] > s[j]) {
                ind = j - 1;
                break;
            }
        }
        s.replace(ind, 1, "");
    }
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (flag == 1) {
            cout << s[i];
        } else if (s[i] != '0') {
            flag = 1;
            cout << s[i];
        }
    }
    if (flag == 0) {
        cout << 0 << endl;
    }
    cout << endl;
    return 0;
}
