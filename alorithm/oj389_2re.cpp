/*************************************************************************
	> File Name: oj390_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 02:54:37 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int n, m, raw;
int num[100005];
long long func(int x) {
    int temp = 1, last = 0;
    for (int i = 0; i < n; i++) {
        if (num[i + 1] - num[last] >= x){
            temp++;
            last = i + 1;
        }
    }
    return temp;
}
int bs() {
    int l = 1, r = num[n - 1] - 1;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        long long  t = func(mid);
        if (t >= m) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    cout << bs() << endl;
    return 0;
}
