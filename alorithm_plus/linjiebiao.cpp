/*************************************************************************
	> File Name: linjiebiao.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Mar 2022 12:32:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, num[105][105][2];
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b;
        num[a][++num[a][0][0]][0] = b;
        num[a][++num[a][0][0]][1] = c;
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 1; j <= num[i][0][0]; j++) {
            cout << "{" << num[i][j][0] << ", " << num[i][j][1] << "} ";
        }
        cout << endl;
    }
    return 0;
}
