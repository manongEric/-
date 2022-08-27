/*************************************************************************
	> File Name: oj240_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Mar 2022 02:05:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[8] = {0, 1, 3, 9, 27, 81, 243, 729};
char mmap[1005][1005];
void func(int x, int y, int cnt) {
    if (cnt == 1) {
        mmap[x][y] = 'X';
        return;
    }
    func(x, y, cnt - 1);
    func(x, y + num[cnt] / 3 * 2, cnt - 1);
    func(x + num[cnt] / 3, y + num[cnt] / 3, cnt - 1);
    func(x + num[cnt] / 3 * 2, y, cnt - 1);
    func(x + num[cnt] / 3 * 2, y + num[cnt] / 3 * 2, cnt - 1);
}
int main() {
    int n;
    func(0, 0, 7);
    while (cin >> n) {
        if (n == -1) {
            break;
        }
        for (int i = 0; i < num[n]; i++) {
            for (int j = 0; j < num[n]; j++) {
                if (mmap[i][j] == 'X') {
                    cout << "X";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << "-" << endl;
    }


    return 0;
}

