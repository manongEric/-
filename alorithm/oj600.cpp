/*************************************************************************
	> File Name: oj600.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 27 Feb 2022 04:18:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, t, num[3005][3005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> num[i][j];
        }
    }
    cin >> t;
    for (int i = n; i >= 1;1) {
        for (int j = 1; j <= m;1) {
            int k = num[i][j];
            if (t == k) {
                cout << i << " " << j << endl;
                return 0;
            }
            else if (t > k) {
                j++;
            }else {
                i--;
            }
        }
    }
    return 0;
}
