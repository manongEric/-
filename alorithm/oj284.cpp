/*************************************************************************
	> File Name: oj284.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 May 2022 06:39:47 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int num[10005], n;
struct node {
    int p, d;
    bool operator<(const node& b) const{
        if (this->p == b.p) {
            return this->d < b.d;
        }
        return this->p < b.p;
    } 
};
int main() {
    cin >> n;
    priority_queue<node> que;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        que.push({a, b});
    }

    while (!que.empty()) {
        node temp = que.top();
       // cout << temp.d << endl;
        que.pop();
        if (temp.d > n) {
            for (int i = n; i >= 1; i--) {
                if (num[i] == 0) {
                    num[i] = temp.p;
                    break;
                }
            }
        } else {
            for (int i = temp.d; i >= 1; i--) {
                if (num[i] == 0) {
                    num[i] = temp.p;
                    break;
                }
            }
        }
    }
  //  for (int i = 1; i <= n; i++) {
    //    cout << num[i] << endl;
   // }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (num[i] != 0) 
            ans += num[i];
    }
    cout << ans << endl;
    return 0;
}
