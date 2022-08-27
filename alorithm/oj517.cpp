/*************************************************************************
	> File Name: oj517.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 08:02:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, ans;
int main(){
    cin >> n;
    for (int i = 1; i <= n / 3; i++) {
        for (int j = i; j <= (n - i) / 2; j++) {
            if (i + j > (n - j - i)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
