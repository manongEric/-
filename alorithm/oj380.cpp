/*************************************************************************
	> File Name: oj380.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Feb 2022 07:35:58 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int id;
    string vote;
};
bool cmp(const node &a, const node &b) {
    if (a.vote.size() == b.vote.size()) {
        return a.vote > b.vote;
    }
    return a.vote.size() > b.vote.size();
}
node s[105];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].vote;
        s[i].id = i;
    }
    sort(s + 1, s + n + 1, cmp);
    cout <<  s[1].id << endl << s[1].vote << endl;
    return 0;
}

