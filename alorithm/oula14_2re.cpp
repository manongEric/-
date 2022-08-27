/*************************************************************************
	> File Name: oula14_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Apr 2022 10:16:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long num[10000005];
long long func(long long n) {
    if (n == 1) {
        return 1;
    }
    if (n <= 10000000 && num[n]) 
        return num[n];
    
    long long t;
    if (n % 2 == 0){
        t  = func(n / 2) + 1;
    } else {
        t = func(3 * n + 1) + 1;
    }   
    if (n < 10000000) {
        num[n] = t;
    } 
    return t;
}
int main() {
    long long ans = 0, id = 0;
    for (int i = 1; i <= 1000000; i++) {
        long long f = func(i);
        if (f  > ans) {
            ans = f;
            id = i;
        }
    }
    cout << id  << endl;
    return 0;
}
