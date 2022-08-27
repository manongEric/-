/*************************************************************************
	> File Name: my_shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Jul 2022 04:25:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

namespace Eric{
    template<class T>
    class shared_ptr{
    public:
        shared_ptr():_ptr(nullptr), _ref(new int{0}) {

        }
        shared_ptr(T* t):_ptr(t), _ref(new int{1}) {//有明确的类型,引用计数是1不是0
            
        }
        //只拷贝栈中数据
        shared_ptr(const shared_ptr<T>& other):_ptr(other._ptr), _ref(other._ref){
            (*_ref)++;
        }
        shared_ptr(shared_ptr<T>&& other):_ptr(nullptr), _ref(new int{0}){
            std::swap(_ptr, other._ptr);
            std::swap(_ref, other._ref);
        }
        virtual ~shared_ptr(){
            if (_ptr){//先判断 共享指针是否在维护一个指针
                (*_ref)--;
            
                if((*_ref) == 0) {
                    delete _ptr;
                    delete _ref;
                }
            }
        }
    public:
        void reset(){//维护的指针地址一定会置为空，若引用计数不为0，则另外开辟新的引用计数,若为0，则删除智能指针的维护，因为，此时的智能指针是最后一个引用
            if (_ptr){//前提是有维护的指针
                (*_ref)--;
                if ((*_ref) == 0){
                    delete _ptr;
                    _ptr = nullptr;
                }else {
                    _ref = new int{0};
                    _ptr = nullptr;
                }
            }
        }

        void swap(shared_ptr<T>& other) {
            std::swap(_ptr, other._ptr);
            std::swap(_ref, other._ref);
        }

        void swap(shared_ptr<T>&& other) {
            this->reset();//针对维护地址
            if (_ref) delete _ref;//针对引用计数地址

            _ptr = other.ptr;
            _ref = other.ref;//浅拷贝， 当前的ref指向内存变了，之前的句柄丢失了，因此需要delete _ref；

            other._ptr = nullptr;
            other._ref = nullptr;
        }
        shared_ptr<T>& operator=(const shared_ptr<T>& other) {
            this->reset();//针对维护地址
            if (_ref) delete _ref;//针对引用计数地址

            _ptr = other._ptr;
            _ref = other._ref;//浅拷贝， 当前的ref指向内存变了，之前的句柄丢失了，因此需要delete _ref；

            (*_ref)++;
            return *this;
        }

        shared_ptr<T>& operator=(shared_ptr<T>&& other) {
            std::swap(_ptr, other._ptr);
            std::swap(_ref, other._ref);

            other.reset();

            return *this;
        }

        operator bool(){return _ptr ? true : false;}//提供一个本类型到bool类型的隐式转换，比较"=="时可转
        T* operator->(){return _ptr;}
        T& operator*() {return *_ptr;}
        inline bool unique(){return (*_ref) == 1 ? true : false;}
        inline int use_count(){return (*_ref);}
        inline T* get() {return _ptr;}

    private:
        T* _ptr;
        int* _ref;
    };
}


int main() {
    Eric::shared_ptr<int> p1{new int{1}};
    Eric::shared_ptr<int> p2{p1};
    Eric::shared_ptr<int> p3;
    p3 = p1;
    p3.swap(p1);
    //p3.reset();
    cout << "p1 use_count = " << p1.use_count() << " unique = " << p1.unique() << " point = " << p1.get() << endl;
    cout << "p2 use_count = " << p2.use_count() << " unique = " << p2.unique() << " point = " << p2.get() << endl;
    cout << "p3 use_count = " << p3.use_count() << " unique = " << p3.unique() << " point = " << p3.get() << endl;
    return 0;
}
