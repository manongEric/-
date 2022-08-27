/*************************************************************************
	> File Name: oj537_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 03:09:48 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
char num[30], ans[30];
int l, c, ycnt, fcnt, cnt, ans_cnt;
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
        int flag = 0;
        ans[ans_cnt++] = num[i];
        if (num[i] == 'a'||
            num[i] == 'e'||
            num[i] == 'o'||
            num[i] == 'u'||
            num[i] == 'i') {
                ycnt++;
            }
        else {
            flag = 1;
            fcnt++;
        }
        if (func(i + 1, left - 1) == -1) {
            return -1;
        }
        if (flag == 0) {
            ycnt--;
        } else {
            fcnt--;
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
