/*************************************************************************
	> File Name: oj386_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Mar 2022 09:20:42 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int id, num;
};
node wt[100005];
bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> wt[i].num;
        wt[i].id = i;
    }
    sort(wt + 1, wt + n + 1, cmp);
    for (int i = 0; i < m; i++) {
        int a, flag = 0;
        cin >> a;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (wt[mid].num == a) {
                flag = 1;
                cout << wt[mid].id << endl;
                break;
            }
            else if (wt[mid].num > a) r = mid - 1;
            else l = mid + 1;
        }
        if (flag == 0) {
            cout << 0 << endl;
        }
    }
    return 0;
}

