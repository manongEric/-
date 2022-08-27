/*************************************************************************
	> File Name: oj509.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 03:40:49 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int t, m;
};
node task[505];
int mark[505] = {1};
int mon, n;
bool cmp(const node &a, const node &b) {
    if (a.m == b.m) {
        return a.t < b.t;
    }
    return a.m > b.m;
}
int main() {
    cin >> mon >> n;
    for (int i = 0; i < n; i++) {
        cin >> task[i].t;
    }
    for (int i = 0; i < n; i++) {
        cin >> task[i].m;
    }
    sort(task, task + n, cmp);
    for (int i = 0; i < n; i++) {
        for (int j = task[i].t; j >= 0; j--) {
            if (mark[j] == 0) {
                mark[j] = 1;
                break;
            }
            if (j == 0) {
                mon -= task[i].m;
            }
        }
    }
    cout << mon << endl;
    return 0;
}

