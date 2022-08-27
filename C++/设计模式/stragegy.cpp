/*************************************************************************
	> File Name: stragegy.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2022 07:34:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Stragegy{
public:
    virtual ~Stragegy(){}
    virtual void sort(int arr[], int n) = 0;
};
//组合
class BubbleSort : public Stragegy{
public:
    void sort(int *num, int n) override{
        cout << "BubbleSort " << endl;
        int flag = 1;
        for (int i = 1; i < n && flag; i++) {
            flag = 0;
            for (int j = 0; j < n - i; j++) {
                if (num[j] < num[j + 1])continue;
                swap(num[j], num[j + 1]);
                flag = 1;
            }
        }
    }
};

class InsertSort : public Stragegy{
public:
    void sort(int *num, int n) override{
    cout << "InsertSort " << endl;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j > 0 && num[j] < num[j - 1]; j--) {
                swap(num[i], num[j - 1]);
            }
        }
    }
};

class SelectSort : public Stragegy{
public:
    void sort(int* num, int n) override{
        cout << "SelectSort " << endl;
        for (int i = 0; i < n - 1; i++) {
            int ind = i;
            for (int j = i + 1; j < n; j++){
                if (num[ind] > num[j]) {
                    ind = j;
                    swap(num[ind], num[i]);
                }
            }
        }
    }
};

class Context{
public:
    void setSrtategy(Stragegy* p) {
        _strategy = p;
    }
    void sort() {
        _strategy->sort(_arr, _size);
    }
    void setData(int* data, int size) {
        _arr = data;
        _size = size;
    }
    void print() {
        for (int i = 0; i < _size; i++) {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }
private:
    int* _arr;
    int _size;
    Stragegy* _strategy;//不同策略指针
};

int main() {
    Context* ctx = new Context();
    int arr[] = {2, 56, 4, -56, 78, -236, 85, -2, 74};
    ctx->setData(arr, sizeof(arr) / sizeof(int));

    Stragegy* p1 = new BubbleSort();
    Stragegy* p2 = new InsertSort();
    Stragegy* p3 = new SelectSort();

    ctx->setSrtategy(p1);
    ctx->sort();
    ctx->print();

    ctx->setSrtategy(p2);
    ctx->sort();
    ctx->print();

    ctx->setSrtategy(p3);
    ctx->sort();
    ctx->print();
    

    delete p1;
    delete p2;
    delete p3;
    return 0;
}
