/*************************************************************************
	> File Name: oj537_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 11:08:49 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
char s[30], ans[30];
int l, c, fcnt, ycnt, cnt, deep;
void func(int start, int left) {
    if (left == 0) {
        if (!(ycnt >= 1 && fcnt >= 2)) return ;
        for (int i = 0; i < l; i++) {
            cout << ans[i];
        }
        cout << endl;
        cnt++;
        if (cnt > 25000) return;
        return;
    }
    for (int i = start; i < c; i++) {
        ans[deep++] = s[i];
        int flag = 0;
        if (s[i] == 'a'|| s[i] == 'o'|| s[i] == 'e' || s[i] == 'i' || s[i] == 'u') {
            ycnt++;
        } else {
            fcnt++;
            flag = 1;
        }
        func(i + 1, left - 1);
        
        if (flag == 0) {
            ycnt--;
        } else {
            fcnt--;
        }
        deep--;
    }
}
int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> s[i];
    }
    sort(s, s + c);
    func(0, l);
    return 0;
}
