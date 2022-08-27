/*************************************************************************
	> File Name: sushushai.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2022 04:17:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 200005
int prime[MAX_N + 5];
int init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        if (prime[0] == 10001) {
            return prime[10001];
        }
       /* for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }*/
        for (int j = i; j <= MAX_N / i; j++) {// 避免爆栈
            prime[j * i] = 1;
        }
    }
    return 0;
}
int main() {
    cout << init() << endl;
    return 0;
}
