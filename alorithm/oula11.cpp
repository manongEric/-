/*************************************************************************
	> File Name: oula11.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Feb 2022 04:08:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[30][30];
int dirx[4] = {-1, 0, 1, 1};
int diry[4] = {1, 1, 1, 0};
int ans;

int main() {
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++){
            cin >> num[i][j];
        }
    }
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++){
            for (int k = 0; k < 4; k++) {
                int t = num[i][j];
                for (int l = 1; l <= 3; l++) {
                    int x = l * dirx[k] + i;
                    int y = l * diry[k] + j;
                    t *= num[i][j];
                }
                ans = max(ans, t);
            }
        }
    }

    return 0;
}
