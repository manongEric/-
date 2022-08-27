/*************************************************************************
	> File Name: bellman_ford_flag.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Mar 2022 03:46:17 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
struct edge {
    int s, e, v;
};
edge edg[200005];   
int n, m, s, edg_cnt, ans[100005];
void add_edg(int a, int b, int c) {
    edg[edg_cnt].s = a;      
    edg[edg_cnt].e = b;      
    edg[edg_cnt++].v = c;    
    
 }                            
int main() {                 
   memset(ans, 0x3f, sizeof(ans));
   cin >> n >> m >> s; 
    ans[s] = 0;
   for (int i = 0; i < m; i++) {
       int a, b, c;         
       cin >> a >> b >> c;  
       add_edg(a, b, c);    
       add_edg(b, a, c);    
      
    }                        
    for (int i = 1; i <= n; i++) {
        int flag = 0;        
        for (int j = 0; j < edg_cnt; j++) {
            int e = edg[j].e, v = edg[j].v, s = edg[j].s;             
            if (ans[e] > ans[s] + v) {
                ans[e] = ans[s] + v;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0x3f3f3f3f) {
            cout << -1 << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
