/*************************************************************************
	> File Name: oj381.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Feb 2022 08:08:38 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct stu{
    string name;
    int id, fin, cla, nov, ans;
    char west, off;
};
bool cmp (const stu &a, const stu &b) {
    if (a.ans == b.ans) {
        a.id < b.id;
    }
    return a.ans > b.ans; 
}
stu s[105];
int n, sum;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].fin >> s[i].cla >> s[i].off >>  s[i].west >> s[i].nov;
        s[i].id = i;
        if(s[i].fin > 80 && s[i].nov >= 1) {
            s[i].ans += 8000;
        }
        if (s[i].fin > 85 && s[i].cla > 80) {
            s[i].ans += 4000;
        }
        if (s[i].fin > 90) {
            s[i].ans += 2000;
        }
        if (s[i].fin > 85 && s[i].west == 'Y') {
            s[i].ans += 1000;
        }
        if (s[i].off == 'Y' && s[i].cla > 80) {
            s[i].ans += 850;
        }
        sum += s[i].ans;
    }
    sort(s, s + n, cmp);
    cout << s[0].name << endl << s[0].ans << endl << sum << endl;
    return 0;
}
