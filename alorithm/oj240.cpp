/*************************************************************************
	> File Name: oj240.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Mar 2022 07:41:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};
char ans[1000][1000];
void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return;
    }
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
}
int main() {
    func(1, 1, 7);
    int t;
    while (cin >> t) {
        if (t == -1) {
            break;
        }
        for (int i = 1; i <= num[t]; i++) {
            for (int j = 1; j <= num[t]; j++) {
                if (ans[i][j] == 'X') {
                    cout << 'X';
                }else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}
