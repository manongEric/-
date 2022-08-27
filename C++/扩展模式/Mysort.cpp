/*************************************************************************
	> File Name: Mysort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Jul 2022 01:15:51 AM CST
 ************************************************************************/

#include<iostream>
#include<time.h>
using namespace std;

#define BEGIN(x) namespace x {
#define END(x) }


void quick_sort(int *num, int l, int r) {
    if (l > r) return;
    int x = l, y = r, z = num[x];
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    } 
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return;
}
BEGIN(test1) 
const int _threashold = 16;
/*void sort(int *first, int *last) {//这里的last 是指向最后一个位置 + 1的地址
    if (first >= last) return;    
    int *x = first, *y = last - 1, z = *first;
    while (x < y)  {  
        while(x < y && *y > z) y--;
        if (x < y) *(x++) = *y;
        while (x < y && *x < z) x++;
        if (x < y) *(y--) = *x;
    }
    *x = z;
    sort(first, x - 1);
    sort(x + 1, last);
    return;
}*/
#define swap(a, b) {\
    __typeof(a)__c = a;\
    a = b, b = __c;\
}
//单边递归优化
int midian(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}
void __sort(int *first, int *last) {//这里的last 是指向最后一个位置 + 1的地址
    while(last - first > _threashold) {    
        int *x = first, *y = last - 1;
        int z = midian(*first, *last, *(first + (last - first) / 2)); //三点取中值
     /*   while (x < y)  {  
            while(x < y && *y > z) y--;
            if (x < y) *(x++) = *y;
            while (x < y && *x < z) x++;
            if (x < y) *(y--) = *x;
        }
        *x = z;
        __sort(x + 1, last);
        last = x;*/
        do {
            while (*x < z) x++;
            while (*y > z) y--;
            if (x <= y) {
                swap(*x, *y);
                ++x, --y;
            }
        }while (x <= y);
        __sort(x, last);
        last = y;
    }
    return;
}

void __final_insertion_sort(int *first, int *last) {
    //找最小值
    int *p = first;
    for (int *q = first + 1; q < last; q++) {
        if (*q < *p) p = q;
    }
    //最小值归位first
    while (p != first) {
        swap(*p, *(p - 1));
        --p;
    }
    for (int *i = first + 2; i < last; i++) {
        p = i;
        //利用最小值已经在最左边的特性，保证不会越界，for逐次遍历各元素，发现不符合时，while归位
        while (*(p) < *(p - 1)) {
            swap(*p, *(p - 1));
            p--;
        }
    }
    return;
}
void sort(int *first, int *last) {
    __sort(first, last);
    __final_insertion_sort(first, last);
    return ;
}
int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) arr[i] = rand() % 100;
    test1::sort(arr, arr + 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#undef swap
END(test1)

//支持任意类型的sort排序
BEGIN(test2)

template<typename T> struct type_trais;//必须先声明是一个模板类，才能模板偏特化

template<typename T>
struct type_trais <T*> {
    typedef T* raw_type;//定义类型
    typedef T value_type;
};
const int _threashold = 16;
/*void sort(int *first, int *last) {//这里的last 是指向最后一个位置 + 1的地址
    if (first >= last) return;    
    int *x = first, *y = last - 1, z = *first;
    while (x < y)  {  
        while(x < y && *y > z) y--;
        if (x < y) *(x++) = *y;
        while (x < y && *x < z) x++;
        if (x < y) *(y--) = *x;
    }
    *x = z;
    sort(first, x - 1);
    sort(x + 1, last);
    return;
}*/
#define swap(a, b) {\
    __typeof(a)__c = a;\
    a = b, b = __c;\
}
//实现vector类也能sort 排序，此时要对vector类处理
template<typename T>
class vector{
public:
    vector(int n = 10):n(n), data(new T[n]) {}
    T* begin() {return data;}
    T* end() {return data + n;}
    T& operator[](int ind) {return data[ind];}
private:
    int n;
    T* data;
};
//单边递归优化
template<typename T>
int midian(T a, T b, T c) {
    if (b < a) swap(a, b);
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);
    return b;
}

template<typename RandomIter>
void __sort(RandomIter first, RandomIter last) {//这里的last 是指向最后一个位置 + 1的地址
    while(last - first > _threashold) {    
        RandomIter x = first, y = last - 1;
        //用类型萃取的方式获得randomiter的原始类型，目的是兼容迭代器类型，后续排序需要
        typename type_trais<RandomIter>::value_type//表示模板类的类型
        z = midian(*first, *last, *(first + (last - first) / 2)); //三点取中值
     /*   while (x < y)  {  
            while(x < y && *y > z) y--;
            if (x < y) *(x++) = *y;
            while (x < y && *x < z) x++;
            if (x < y) *(y--) = *x;
        }
        *x = z;
        __sort(x + 1, last);
        last = x;*/
        do {
            while (*x < z) x++;
            while (*y > z) y--;
            if (x <= y) {
                swap(*x, *y);
                ++x, --y;
            }
        }while (x <= y);
        __sort(x, last);
        last = y;
    }
    return;
}

template<typename RandomIter>
void __final_insertion_sort(RandomIter first, RandomIter last) {
    //找最小值
    RandomIter p = first;
    for (RandomIter q = first + 1; q < last; q++) {
        if (*q < *p) p = q;
    }
    //最小值归位first
    while (p != first) {
        swap(*p, *(p - 1));
        --p;
    }
    for (RandomIter i = first + 2; i < last; i++) {
        p = i;
        //利用最小值已经在最左边的特性，保证不会越界，for逐次遍历各元素，发现不符合时，while归位
        while (*(p) < *(p - 1)) {
            swap(*p, *(p - 1));
            p--;
        }
    }
    return;
}

template<typename RandomIter>
void sort(RandomIter first, RandomIter last) {
    __sort(first, last);
    __final_insertion_sort(first, last);
    return ;
}

template<typename RandomIter>
void output(RandomIter first, RandomIter last) {
    while(first < last) {
        cout << *first << " ";
        first++;
    }
    cout << endl;
    return;
}
int main(){
    int arr_i[10];
    double arr_d[10];
    for (int i = 0; i < 10; i++) arr_i[i] = rand() % 100;
    for (int i = 0; i < 10; i++) arr_d[i] = rand() % 10000 * 1.0 / 100;
    sort(arr_i, arr_i + 10);
    sort(arr_d, arr_d + 10);
    output(arr_i, arr_i + 10);
    output(arr_d, arr_d + 10);

    test2::vector<int> v_arr(10);
    for (int i = 0; i < 10; i++) v_arr[i] = rand() % 100;
    sort(v_arr.begin(), v_arr.end());
    output(v_arr.begin(), v_arr.end());
}
END(test2)


int main() {
    //test1::main();
    test2::main();
    return 0;
}
