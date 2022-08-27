/*************************************************************************
	> File Name: xianxingshai_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 04:49:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int prime[200005];
void init() {
    for (int i = 2; i <= 200005; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > 200005) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    cout << prime[10001] << endl;
    return 0;
}
