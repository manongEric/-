/*************************************************************************
	> File Name: oj534.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 24 May 2022 12:31:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[25], mark[1000] = {1}, sum, n, ans;

void func(int s) {
    if (!mark[sum]) {
        ans++;
        mark[sum] = 1;
    }
    for (int i = s; i < n; i++) {
        sum += num[i];
        func(i + 1);
        //mark[sum] = 0;
        sum -= num[i];
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    func(0);
    cout << ans << endl;
    return 0;
}
