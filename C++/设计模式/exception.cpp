/*************************************************************************
    > File Name: exception.cpp
    > Author: 
    > Mail: 
    > Created Time: Sat 30 Jul 2022 02:18:14 PM CST
 ************************************************************************/

#include<iostream>
#include<exception>
using namespace std;

const char* EX_LOGIN = "ex_login";
const char* EX_LOGIN_FAILED = "ex_login_faiked";

class Base{virtual void member(){}};
class Derived : Base{};
class Myexception : public exception {
public:
    const char* what() {
        return "kaikeba exception";
    }
};
int main() {
    try{
       // throw "123";
        //throw 123;
        //throw EX_LOGIN_FAILED;
        throw new Myexception;
   //     Base b;
     //   Derived& rd = dynamic_cast<Derived&>(b);
    }
    catch(bad_cast *e) {//系统异常处理
        cout << "bad_cast " << e->what() << endl;
    }
    catch(Myexception* e) {
        cout << "Myexception " << e->what() << endl;
    }
    catch(const char* e) {//异常的捕获要精确匹配
        cout << "const char* = " << e << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
    } 

    catch(...) {
        cout << "default exception" << endl;
    }


    return 0;
}
