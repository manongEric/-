/*************************************************************************
	> File Name: my_vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Jul 2022 06:02:59 PM CST
 ************************************************************************/

#include<iostream>
#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(Eric)
template<class T>
class vector{
public:
    using iterator = T*;
private:
    T* _begin;
    T* _end;
    T* _capacity;

public:
    vector():_begin(nullptr), _end(nullptr), _capacity(nullptr){
        
    }
    vector(size_t size, const T& value = T()):_begin(nullptr), _end(nullptr), _capacity(nullptr){
        
    }
    vector(const vector<T>& vec):_begin(nullptr), _end(nullptr), _capacity(nullptr){
        if (this == &vec) return;
        reserse(vec.capacity());
        //这里并不能用memcpy拷贝，因为 如果拷贝的是内置类型的元素，memcpy即高效又不会出错，但如果拷贝的是自定义类型元素，并且自定义类型元素中涉及到资源管理时，就会出错，因为memcpy的拷贝实际是浅拷贝
        //如果这里涉及到深拷贝，那么memcpy会忽略这一个过程或者出错
        for (int i = 0; i < vec.size(); i++) {
            *_end = *(vec._begin + i);
            _end++;
        }
    }
    vector(vector<T>&& vec):_begin(vec._begin), _end(vec._end), _capacity(vec._capacity) {
        vec._begin = nullptr;
        vec._end = nullptr;
        vec._capacity = nullptr;
    }
    //delete a;    
    //仅释放了a指针指向的全部内存空间 但是只调用了a[0]对象的析构函数 剩下的从a[1]到a[9]这9个用户自行分配的m_cBuffer对应内存空间将不能释放 从而造成内存泄漏
    //delete [] a;
    //调用使用类对象的析构函数释放用户自己分配内存空间并且   释放了a指针指向的全部内存空间
    // 对于像int/char/long/int*/struct等等简单数据类型，由于对象没有destructor，所以用delete 和delete [] 是一样的！但是如果是C++对象数组就不同了！
    virtual ~vector(){
        if (_begin) delete[] _begin;
    }
    void reserse(size_t n) {
        // n:要生成的目标内存大小 
        if (n > capacity()){
            size_t len = size();
            T *p = nullptr;
            if (_begin) {
                p = (T*)realloc(_begin, n * sizeof(T));
                if (p == nullptr) 
                    std::cout << "realloc failed\n";
            } else {
                p = (T*)malloc(sizeof(T) * n);
            }
            _begin = p;
            _end = _begin + len;
            _capacity = _begin + n;
            // T* p = new T[n];
            // if (_begin) delete _begin;
            // _begin = p;
        }
    }
void push_back(const T& value) {
    if (_end == _capacity) {
        size_t len = size();
        if (len == 0) len = 1;
        else len = len * 2;
        reserse(len);
    }
    *_end = value;
    _end++;
}
void pop_back() {
    _end--;
}

T& operator[](size_t index) {
    return *(_begin + index);
}
public:
    inline size_t size() {return _end - _begin;}
    inline size_t capacity() {return _capacity - _begin;}
    iterator begin() {
        return _begin;
    }
    iterator end() {
        return _end;
    }
};
int main() {
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(i);
        std::cout << "size = " << arr.size() << "capacity = " << arr.capacity() << std::endl;
    }
    arr.pop_back();
    arr.pop_back();
    arr.pop_back();
    arr[0] = 99;
    for (auto it : arr) {
        std::cout << it << std::endl;
    }
    return 0;
}
END(Eric)

int main() {
    Eric::main();
    return 0;
}
