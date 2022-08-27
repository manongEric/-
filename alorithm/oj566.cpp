/*************************************************************************
	> File Name: oj566.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 May 2022 11:53:06 PM CST
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int n, m, cnt;
int main(){
    cin >> n >> m;
    vector<vector<string>> vec(m, vector<string>());
    unordered_map<string, int> map;
    for (int i = 0; i < m; i++) {
        string s, b;
        cin >> s >> b;
        if (!map.count(s)) {
            map[s] = cnt;
            vec[cnt].push_back(s);
            vec[cnt].push_back(b);
            cnt++;
        } else {
            vec[map[s]].push_back(b);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (j != 0) cout << " ";
            cout << vec[i][j];
        }
        cout << endl;
    }


    return 0;
}
