/*************************************************************************
	> File Name: prime.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2022 03:52:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n;
int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!is_prime(i)) continue; 
        cout << i << endl;
    }
    return 0;
}
