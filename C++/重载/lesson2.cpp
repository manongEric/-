/*************************************************************************
	> File Name: lesson2.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Jul 2022 08:51:01 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Print{
private:
    int x;
public:
    Print(int n):x(n) {

    }
    void operator()(int n){
        cout << "operator function" << " " << n * 100 + x<<endl;
    }
    void call() {
        cout << "operator function" << endl;
    }
};
void print(int n) {
    cout << n * 100 + 3 << endl;
}

class checkNumber{
private: 
    int min, max;
public:
    checkNumber(int a, int b):min(a), max(b){
        
    }
    bool operator()(int n) {
        if (n >= min && n <= max) return true;
        return false;
    }
};
int main() {
    Print p(1);
   // p();//仿函数
   // p.call();
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(100);
    arr.push_back(-100);
    for_each(arr.begin(), arr.end(), print);//通过函数遍历输出
    for_each(arr.begin(), arr.end(), Print(3));//通过仿函数遍历输出, 更加方便固定高效

    int count1 = count_if(arr.begin(), arr.end(), checkNumber(1, 3));
    cout << "count 1 - 3 : " << count1 << endl; 
    int count2 = count_if(arr.begin(), arr.end(), checkNumber(1, 500));
    cout << "count 1 - 500 : " << count2 << endl; 

    return 0;
}
