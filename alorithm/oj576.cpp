/*************************************************************************
	> File Name: oj576.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Mar 2022 03:02:02 PM CST
 ************************************************************************/

#include<iostream>
#include<unordered_map>
using namespace std;
int n, k;
long long ans;
int main() {
    cin >> n >> k;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    for (int i = 0; i < n; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        m1[s] = b;
        m2[s] = a;
    }
    for (int i = 1; i <= k; i++) {
        string s;
        int a;
        cin >> s >> a;
        if (m1[s] < a) {
            cout << "-" << i << endl;
            return 0;
        }
        m1[s] -= a;
        ans += m2[s] * a;
    }
    cout << ans << endl;
    return 0;
}

