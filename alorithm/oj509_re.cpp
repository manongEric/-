/*************************************************************************
	> File Name: oj509_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Mar 2022 04:41:24 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int mon, tim;
};
node task[505];
int m, n, ans;
int mark[505] = {1};
bool cmp(const node &a, const node &b) {
    if (a.mon == b.mon) {
        return a.tim > b.tim;
    }
    return a.mon > b.mon;
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> task[i].tim;
    }
    for (int i = 1; i <= n; i++) {
        cin >> task[i].mon;
    }
    sort(task + 1, task + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = task[i].tim; j >= 1; j--) {
            if (mark[j] == 0) {
                mark[j] = 1;
                break;
            } 
            if (j == 1) {
                m -= task[i].mon;
            }
        }
    }
    cout << m << endl;
    return 0;
}

