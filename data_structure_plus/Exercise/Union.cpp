/*************************************************************************
	> File Name: Union.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 May 2022 08:07:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int Union[1000005];

int find(int x) {
    if (x == Union[x]) {
        return x;
    }
    return Union[x] = find(Union[x]);
} 

void merge(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    Union[fa] = fb;
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        Union[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (i == Union[i]);
    }
    cout << ans << endl;
    return 0;
}
