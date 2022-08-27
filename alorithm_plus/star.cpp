/*************************************************************************
	> File Name: star.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Mar 2022 02:15:48 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
struct edge{
    int e, v, next;
};
edge edg[105];
int n, m, head[105];
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].e = b;
        edg[i].v = c;
        edg[i].next = head[a];
        head[a] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = head[i]; j != -1; j = edg[j].next) {
            cout << "{" << edg[j].e << ", " << edg[j].v << "} ";
        }
        cout << endl;
    }

    return 0;
}
