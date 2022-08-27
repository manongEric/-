/*************************************************************************
	> File Name: oj481_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Mar 2022 03:52:58 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int num[15][2], r;
void print(int cnt) {
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i < cnt; i++) {
        cout << num[i][0] << ":" << num[i][1] << endl;
        ans1 += num[i][0];
        ans2 += num[i][1];
    }
    cout << ans1 << ":" << ans2 << endl;
}
int main() {
    cin >> r;
    for (int i = 1; i <= 10; i++) {
        int num1[10] = {0}, num2[10] = {0};
        for (int j = 0; j < 8; j++) {
            cin >> num1[j];
            if (num1[j] == -1) {
                print(i);
                return 0;
            }    
        }
        for (int k = 0; k < 8; k++) {
            cin >> num2[k];
        }
        sort(num1, num1 + 8);
        sort(num2, num2 + 8);
        if (num1[0] < num2[0]) {
            for (int j = 0; j < 8 && num1[j] < num2[0] && num1[j] <= r; j++) {
                num[i][0]++;
            }
        } else {
            for (int j = 0; j < 8 && num2[j] < num1[0] && num2[j] <= r; j++) {
                num[i][1]++;
            }
        }
    }
    print(11);
    return 0;
}
