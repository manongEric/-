/*************************************************************************
	> File Name: oj485.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Mar 2022 12:55:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, ans, sum;
int num[105];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    int avg = sum / n;
    for (int i = 0; i < n - 1; i++) {
        if (num[i] != avg) {
            num[i + 1] += num[i] - avg;
            cout << num[i] << " ";
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
