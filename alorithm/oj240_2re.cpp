/*************************************************************************
	> File Name: oj240_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 07:49:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
char mmap[1005][1005];
int num[8] = {0, 1, 3, 9, 27, 81, 243, 729}, n;
void func(int x, int y, int cnt) {
    if (cnt == 1) {
        mmap[x][y] = 'X';
        return;
    }
    func(x, y, cnt - 1);
    func(x, y + num[cnt] / 3 * 2, cnt - 1);
    func(x + num[cnt] / 3 , y + num[cnt] / 3, cnt - 1);
    func(x + num[cnt] / 3 * 2, y, cnt - 1);
    func(x + num[cnt] / 3 * 2, y + num[cnt] / 3 * 2, cnt - 1);
}
int main() {
    func(0, 0, 7);
    while (cin >> n){
        if (n == -1) break;
        for (int i = 0; i < num[n]; i++) {
            for (int j = 0; j < num[n]; j++) {
                if (mmap[i][j] == 'X') cout << "X";
                else cout << " ";
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}
