/*************************************************************************
	> File Name: oj599.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 27 Feb 2022 03:44:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, t;
int num[1000005], mark[10000005];
int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        mark[num[i]] = i; 
    }
    for (int i = 1; i <= n; i++) {
        int target = t - num[i];
        if (mark[target] != 0) {
            cout << i - 1 << " " << mark[target] - 1 << endl;
            return 0;
        }
    }
    /*for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0, j = n - 1; 1;) {
        int l = num[i], r = num[j];
      //  cout << l << " " << r << endl;
        if (l + r == t) {
            cout << i << " " << j;
            return 0;
        }else if (l + r > t) {
            j--;
        }else {
            i++;
        }
    }*/
    return 0;
}
