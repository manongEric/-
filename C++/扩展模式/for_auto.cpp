/*************************************************************************
	> File Name: for_auto.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Jul 2022 02:35:30 PM CST
 ************************************************************************/

#include<iostream>
#include<time.h>
#include<vector>
using namespace std;
#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(test1) 

int main(){
    vector<int> arr;
    for (int i = 0; i < 5; i++) arr.push_back(rand() % 100);
    for (auto x : arr){
        cout << x << endl;   
    }
    return 0;
}
END(test1)


BEGIN(test2)

class A{
private:
    int *data, n;
public:
    A(int n = 5):n(n) {
        data = new int[n];
        for (int i = 0; i < n; i++) data[i] = rand() % 100;
    }
    /*for (auto iter = a.begin(); iter != a.end(); iter++) {
     * auto x = *iter;
    * }*/
    int* begin() {return data;}
    int* end() {return data + n;}
};


int main(){
    A a;//执行的是默认构造， 在类中我们默认构造的默认值是5
    for (auto x : a){//for auto 对某对象使用
        cout << x << endl;
    }
}
END(test2)


int main(){
    test2::main();

    return 0;
}
