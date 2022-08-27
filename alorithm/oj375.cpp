/*************************************************************************
	> File Name: oj375.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Feb 2022 10:53:50 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int chi, mat, eng, id, sum;
};
bool cmp(const node &a, const node &b) {
    if (a.chi == b.chi && a.sum == b.sum){
        return a.id < b.id;
    }
    if (a.sum == b.sum) {
        return a.chi > b.chi;
    }
    return a.sum > b.sum;
}
node stu[305];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stu[i].chi >> stu[i].mat >> stu[i].eng;
        stu[i].id = i;
        stu[i].sum += stu[i].chi + stu[i].mat + stu[i].eng;
    }
    sort(stu + 1, stu + n + 1, cmp);
    for (int i = 1; i <= 5; i++) {
        cout << stu[i].id << " " << stu[i].sum << endl;
    }
    return 0;
}

