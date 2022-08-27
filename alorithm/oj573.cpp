/*************************************************************************
	> File Name: oj573.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2022 12:10:42 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node{
    int id, offset, next;
    bool operator <(const node &b) const{
        if (this->next == b.next) {
            return this->id > b.id;
        }
        return this->next > b.next;
    }
};
int main() {
    string s;
    priority_queue<node> que;
    while (1) {
        cin >> s;
        if (s == "#"){
            break;
        }
        int id, offset;
        cin >> id >> offset;
        que.push({id, offset, offset});
    }
    int q;
    cin >> q;
    while (q--) {
        node temp = que.top();
        que.pop();
        cout << temp.id << endl;
        que.push({temp.id, temp.offset, temp.next + temp.offset});
    }

    return 0;
}
