/*************************************************************************
	> File Name: function.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Aug 2022 11:50:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(test1)
int func1(int a, int b) {
    cout << "function 1" << endl;
    return a + b;
}
class FUNC_T{
public:
    int operator()(int a, int b) {
        cout << "FUNC_T CLASS" << endl;
        return a + b;
    }
};
template<typename RT, typename ...ARGS>
class base_function{
public:
    virtual RT run(ARGS... args) = 0;
};

template<typename RT, typename ...ARGS>
class normal_function : public base_function<RT, ARGS...>{//模板类 带<类型>
public:
    normal_function(RT(*ptr)(ARGS...)):ptr(ptr){}
    RT run(ARGS... args) override{
        return ptr(std::forward<ARGS>(args)...);
    }
private:
    RT(*ptr)(ARGS...); //关于ptr的函数指针；
};
template<typename CLAAS_T, typename RT, typename ...ARGS>
class object_function : public base_function<RT, ARGS...>{
public:
    object_function(const CLAAS_T &func_obj):func_obj(func_obj){}
    RT run(ARGS... args) override {
        return func_obj(std::forward<ARGS>(args)...);
    }
private:
    CLAAS_T func_obj;
};
template<typename RT, typename ...ARGS> class function;
template<typename RT, typename ...ARGS>
class function<RT(ARGS...)>{//function底层实行偏特化的语法格式
public:
    function(): ptr(nullptr) {}
    function(RT(*func_ptr)(ARGS...))://传入正常的函数指针
    ptr(new normal_function<RT, ARGS...>(func_ptr)) {}//模板类实例化时要带上"<类型> +(参数)”

    template<typename CLAAS_T>
    function(CLAAS_T& func) : 
    ptr(new object_function<CLAAS_T, RT, ARGS...>(func)){}//参数是函数对象 "func"

    RT operator()(ARGS... args) {//重载()
        return ptr->run(std::forward<ARGS>(args)...);
    }

private:
    base_function<RT, ARGS...> *ptr; //模板类指针
};
int main() {
    FUNC_T func2;
    function<int(int, int)> super_p;
    super_p = func1;
    cout << super_p(3, 4) << endl;
    super_p = func2;
    cout << super_p(3, 4) << endl;

    return 0;
}

END(test2)
int main() {
    test1::main();

    return 0;
}
