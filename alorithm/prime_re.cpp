/*************************************************************************
	> File Name: prime_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 04:22:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n;
int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main() {
    cin >> n;
    for (int i = 2; i < n; i++) {
        if (!is_prime(i)) continue;
        cout << i << endl;
    }

    return 0;
}
