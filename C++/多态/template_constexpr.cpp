/*************************************************************************
	> File Name: template_constexpr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Jul 2022 02:34:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Abstract{
public:
    virtual ~Abstract(){};//别省大括号
};
class PersonA : public Abstract{
public:
    void speakEnglish(){
        cout << "call English" << endl;
    }
};

class PersonB : public Abstract{
public:
    void speakChinese(){
        cout << "call Chinese" << endl;
    }
};
//条件编译
template<class T>
void speak(T t){
    //这里要加上contexpr，保持在编译阶段修饰对象不可变，否则会报错，T t，T既可以符合A也可以符合B
    if constexpr(std::is_same<T, PersonA>{}){
        t.speakEnglish();
    }else if constexpr(std::is_same<T, PersonB>{}){
        t.speakChinese();
    }
}

class Person{
public:
    static void speak(Abstract* person){
        if (dynamic_cast<PersonA*>(person)) {//e的类型是目标type的基类，当e是指针指向派生类对象，或者基类引用引用派生类对象时，类型转换才会成功，当e指向基类对象，试图转换为派生类对象时，转换失败。
            ((PersonA*)person)->speakEnglish();
        }else if (dynamic_cast<PersonB*>(person)) {
            ((PersonB*)person)->speakChinese();
        }
    }

};

int main() {
    cout << "=========利用模板的条件编译======="  << endl;
    PersonB a, b;
    speak(a);
    cout << "=========抽象类========" << endl;
    Person::speak(&a);
    return 0;
}
