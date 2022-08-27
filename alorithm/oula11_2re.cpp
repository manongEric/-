/*************************************************************************
	> File Name: oula11_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 08:27:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int dir[4][2] = {1, 1, 1, 0, 1, -1, 0, -1};
int num[30][30], ans;
int main() {
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            cin >> num[i][j];
        }
    }
    
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                int t = num[i][j];
                for (int l = 1; l <= 3; l++) {
                    int x = l * dir[k][0];
                    int y = l * dir[k][1];
                    t *= num[x][y];
                }
                ans = max(ans, t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
