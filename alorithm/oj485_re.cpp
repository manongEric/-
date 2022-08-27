/*************************************************************************
	> File Name: oj485_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 02:22:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[105], n, cnt, avg;
int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0 ; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    avg = sum / n;
    for (int i = 0; i < n - 1; i++) {
        if (num[i] < avg) {
            num[i + 1] -= avg - num[i];
            cnt++;
        } else if (num[i] > avg){
            num[i + 1] += num[i] - avg;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
