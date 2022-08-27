/*************************************************************************
	> File Name: linjiejuzhen.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Mar 2022 10:25:20 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int arr[50][50], n, m;
int main() {
    cin >> n >> m;
    for (int j = 1; j <= m; j++) {
        int a, b ,c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] != 0) {
                cout << "{" << i << "->" << j << ", " << arr[i][j] << "} ";
            }
        }
        cout << endl;
    }


    return 0;
}
