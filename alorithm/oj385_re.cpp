/*************************************************************************
	> File Name: oj385_re.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Apr 2022 11:50:51 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct node{
    int time, coun;
};
int mark[500005], num, cnt;
int main() {
    scanf("%d", &num);
    queue<node> que;
    while(num--) {
        int t, n;
        scanf("%d%d", &t, &n);
        while(t - que.front().time >= 86400) {
            node temp = que.front();
            que.pop();
            mark[temp.coun]--;
            if (mark[temp.coun] == 0) 
                cnt--;
        }
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            que.push({t, a});
            if (mark[a] == 0)
                cnt++;
            mark[a]++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
