/*************************************************************************
	> File Name: oj375_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Apr 2022 02:05:08 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct node {
    int id, c, m, e, sum;
};
node stu[305];
bool cmp (const node &a, const node &b) {
    if (a.sum == b.sum) {
        if (a.c == b.c) {
            return a.id < b.id;
        }
        return a.c > b.c;
    }
    return a.sum > b.sum;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].c >> stu[i].m >> stu[i].e;
        stu[i].sum = stu[i].e + stu[i].m + stu[i].c;
        stu[i].id = i + 1;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < 5; i++) {
        cout << stu[i].id << " " << stu[i].sum << endl;
    }
    return  0;
}
