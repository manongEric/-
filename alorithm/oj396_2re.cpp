/*************************************************************************
	> File Name: oj396_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 11:40:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int mmap[1005][1005], n;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
        if (mmap[xx][yy] == 0) {
            mmap[xx][yy] = 3;
            func(xx, yy);
        }
    }
} 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    mmap[0][0] = 3;
    func(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) cout << " ";
            if (mmap[i][j] == 3) {
                cout << 0;
            } else if (mmap[i][j] == 1) {
                cout << 1;
            } else {
                cout << 2;
            }
        }
        cout << endl;
    }
    return 0;
}
