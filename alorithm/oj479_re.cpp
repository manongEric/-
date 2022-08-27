/*************************************************************************
	> File Name: oj479_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Mar 2022 03:09:08 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int num11[6000][2],num21[3000][2], cnt11, cnt21;
void print() {
    for (int i = 0; i <= cnt11; i++) {
        cout << num11[i][0] << ":" << num11[i][1] << endl;
    }
    cout << endl;
    for (int i = 0; i <= cnt21; i++) {
        cout << num21[i][0] << ":" << num21[i][1] << endl;
    }
}
int main() {
    char s[30];
    while(cin >> s) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'E') {
                print();
                return 0;
            }else if (s[i] == 'W') {
                num11[cnt11][0]++;
                num21[cnt21][0]++;
            }else {
                num11[cnt11][1]++;
                num21[cnt21][1]++;
            }
            if ((num11[cnt11][0] >= 11 || num11[cnt11][1] >= 11) && abs(num11[cnt11][0] - num11[cnt11][1]) >= 2 ) {
                cnt11++;
            }
            if ((num21[cnt21][0] >= 21 || num21[cnt21][1] >= 21) && abs(num21[cnt21][0] - num21[cnt21][1]) >= 2 ) {
                cnt21++;
            }
        }
    }
    return 0;
}
