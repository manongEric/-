/*************************************************************************
	> File Name: oj537.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 15 Mar 2022 02:44:14 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int ycnt, fcnt, cnt, l, c, ans_cnt;
char num[30], ans[30];
int func(int s, int left) {
    if (left == 0) {
        if (!(ycnt >= 1 && fcnt >= 2)) return 0;
        for (int i = 0; i < l; i++) {
            cout << ans[i];
        }
        cout << endl;
        cnt++;
        if (cnt == 25000) return -1;
        return 0;
    }
    for (int i = s; i < c; i++) {
        ans[ans_cnt++] = num[i];
        int flag = 0;
        if (num[i] == 'a' || 
            num[i] == 'e' ||
            num[i] == 'i' ||
            num[i] == 'o' ||
            num[i] == 'u') {
                ycnt++;
            }
        else {
            fcnt++;
            flag = 1;
        }
        if (func(i + 1, left - 1) == -1) {
            return -1;
        }
        if (flag == 1) {
            fcnt--;
        } else {
            ycnt--;
        }
        ans_cnt--;
    }
}
int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> num[i];
    }
    sort(num, num + c);
    func(0, l);
    return 0;
}
