/*************************************************************************
	> File Name: oj569.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 06 Mar 2022 03:32:35 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
struct node {
    double salt, water;
};
int main() {
    int n;
    double c, mz, my;
    stack<node> sta;
    cin >> my >> c;
    mz = c / 100.0 * my;
   // sta.push((node){mz, my});
    cin >> n;
    for (int i = 0; i < n; i++) {
        char s;
        cin >> s;
        if (s =='P') {
            double mzz, myy, cc;
            cin >> myy >> cc;
            mzz = cc / 100.0 * myy;
            my += myy;
            mz += mzz;
            sta.push((node){mzz, myy});
          //  printf("%d %.5lf\n", (int)sta.top().water, sta.top().salt * 100.0 / sta.top().water);
        }else {
            if (!sta.empty()) {
                mz -= sta.top().salt;
                my -= sta.top().water;
                sta.pop();
            }
           // printf("%d %.5lf\n", (int)sta.top().water, sta.top().salt * 100.0 / sta.top().water);
        }
        printf("%d %.5f\n", (int)my, mz / my * 100.0);
    }

    return 0;
}

