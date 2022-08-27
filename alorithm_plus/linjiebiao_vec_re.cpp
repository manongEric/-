/*************************************************************************
	> File Name: linjiebiao_vec_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Mar 2022 01:39:27 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct edge {
    int e, v;
};
int n, m;
int main() {
    cin >> n >> m;
    vector<vector<edge> > edg(n + 1, vector<edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[a].push_back((edge){b, c});
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 0; j < edg[i].size(); j++) {
            cout << "{" << edg[i][j].e << ", " << edg[i][j].v << "} ";
        }
        cout << endl;
    }

    return 0;
}

