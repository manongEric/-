/*************************************************************************
	> File Name: oj569_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Mar 2022 10:08:52 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
struct node {
    double salt, water;
};
double c, v;
int main() {
    int n;
    stack<node> sta;
    cin >> v >> c;
    double m = v * c / 100.0;
    //sta.push((node){m, v});
    cin >> n;
    for (int i = 0; i < n; i++) {
        char p;
        double v1, c1, m1;
        cin >> p;
        if (p == 'P') {
            cin >> v1 >> c1;
            m1 = v1 * c1 / 100.0;
            m += m1;
            v += v1;
            sta.push((node){m1, v1});
        } else {
            if (!sta.empty()) {
                m -= sta.top().salt;
                v -= sta.top().water;
                sta.pop();
            }
        }
        printf("%d %.5lf\n", (int)v, m / v * 100.0);
    }


    return 0;
}

