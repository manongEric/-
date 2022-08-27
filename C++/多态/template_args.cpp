/*************************************************************************
	> File Name: template_args.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2022 02:23:04 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


namespace Eric{
    template <class T>
    T sum(T t){
        return t;
    }

    template<class T, class ...ARGS>
    T sum(T t, ARGS ...args){//...args 代表所有参数数量是不定的
        //运行阶段执行完，并不会在编译阶段得到结果，只是将sum(args)所有函数推导出来
        return t + sum(args...);//args... 代表从...args中拿出一个，后面的参数数量是不定的，是最后一个时，需要跳转
    }

    template<class T>
    void print(const T& t){
        cout << t << endl;
    }
    template<class T, class ...ARGS>
    void print(const T& t, ARGS ...args) {
        cout << t << " ";
        print(args...);
    }
}

int main() {
    cout << Eric::sum(1, 3, 4, 5, 67, 781, 10) << endl;

    cout << "========print=========" << endl;
    Eric::print(1, "asdas", 1.0f);

    return 0;
}
