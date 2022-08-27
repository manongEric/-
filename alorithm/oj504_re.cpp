/*************************************************************************
	> File Name: oj504_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Mar 2022 04:51:42 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int main() {
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ind = s.size() - 1;
        for (int j = 1; j < s.size(); j++) {
            if (s[j - 1] > s[j]){
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
        }else if (s[i] != '0') {
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

