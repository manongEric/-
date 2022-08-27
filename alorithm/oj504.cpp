/*************************************************************************
	> File Name: oj504.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Mar 2022 07:25:28 PM CST
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
            //cout << ind << endl;
        }
        s.replace(ind, 1, "");
    }
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (flag == 1) {
            cout << s[i];
        }else if (s[i] != '0') {
            cout << s[i];
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << 0;
    }
    cout << endl;
    return 0;
}
