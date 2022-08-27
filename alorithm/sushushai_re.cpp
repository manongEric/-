/*************************************************************************
	> File Name: sushushai_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 04:27:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int prime[100];
void init() {
    for (int i = 2; i <= 100; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        for (int j = i * i; j <= 100; j += i) {
            prime[j] = 1;
        }
    }
}
int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) {
        cout << prime[i] << endl;
    }
    return 0;
}
