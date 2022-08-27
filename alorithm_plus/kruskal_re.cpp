/*************************************************************************
	> File Name: kruskal_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Apr 2022 12:04:48 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct edge {
    int s, e, v;
    bool operator< (const edge &b) const{
        return this->v < b.v;
    }
};
edge edg[100005];
int n, m, cnt, ans, my_union[100005];
void init() {
    for (int i = 1; i <= n; i++) {
        my_union[i] = i;
    }
}
int find_fa(int x) {
    if (my_union[x] == x) {
        return x;
    }
    return my_union[x] = find_fa(my_union[x]);
}
int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        cin >> edg[i].s >> edg[i].e >> edg[i].v;
    }
    sort(edg, edg + m);
    for (int i = 0; i < m; i++) {
        int fa = find_fa(edg[i].s), fb = find_fa(edg[i].e);
        if (fa != fb) {
            my_union[fa] = fb;
            ans += edg[i].v;
            cnt++;
        }
        if (cnt == n - 1) {
            cout << ans << endl;
            return 0;
        }
    }
    return -1;
}
