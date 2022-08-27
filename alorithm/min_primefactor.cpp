/*************************************************************************
	> File Name: min_primefactor.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2022 07:17:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int prime[105];
void init() {
    for (int i = 2; i <= 100; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= 100; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
}
int main() {
    init();
    for (int i = 2; i <= 100; i++) {
        cout << i << " : " << prime[i] << endl;
    }
    return 0;
}
