/*************************************************************************
	> File Name: oj534_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 08:52:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int mark[1005] = {1}, num[25], n, ans;
void func(int s, int sum) {
    if (mark[sum] == 0) {
        mark[sum] = 1;
        ans++;
    }
    for (int i = s; i <= n; i++) {
        sum += num[i];
        func(i + 1, sum);
        sum -= num[i];
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    func(1, 0);
    cout << ans << endl;
    return 0;
}
