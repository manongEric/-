/*************************************************************************
	> File Name: sushushai.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2022 04:17:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100
int prime[MAX_N + 5];
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
       /* for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }*/
        for (int j = i; j <= MAX_N / i; j++) {// 避免爆栈
            prime[j * i] = 1;
        }
    }
}
int main() {
    init();
    cout << prime[0] << endl;
    cout << prime[1] << endl;
    return 0;
}
