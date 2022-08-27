/*************************************************************************
	> File Name: oj509_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 03:23:29 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int mon, time;
};
bool cmp(const node &a, const node &b) {
    if (a.mon == b.mon) {
        return a.time > b.time;
    }
    return a.mon > b.mon;
}
node task[505];
int n, mark[505] = {1}, money;
int main() {
    cin >> money;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> task[i].time;
    }
    for (int i = 1; i <= n; i++) {
        cin >> task[i].mon;
    }
    sort(task + 1, task + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = task[i].time; j >= 1; j--) {
            if (mark[j] != 1) {
                mark[j] = 1;
                break;
            }
            if (j == 1) {
                money -= task[i].mon;
            }
        }
    }
    cout << money << endl;
    return 0;
}
