/*************************************************************************
	> File Name: _static.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jun 2022 08:24:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class People{
protected:
    string name;
    double weight;
    double height;
    const int age;// = 18;
    int level;

public:
    static int s_total;
    const static int s_count = 123; //静态存储区的常量区，不可修改
    static People* people;
private:
    People() :age(18){
        cout << "call construcor " << endl;
    }
    ~People() {
        cout << "call desconstructor" << endl;
    }
public:
    static People* getInstance() {//调用的时候进行实例化
        if (people == nullptr) {
            people = new People();
        }
        return people;
    }
    static People* create() {
        return new People();
    }
    static void release(People* p) {
        delete p;
    }
    void say() {
        cout << "age = " << this->age << endl;
    }

    void eat(People* p) {
        p->weight++;
    }
    void addAge() const {
        s_total++;
     //   this->level++;
        int *p = (int *)&this->level;
        *p = 123;
        cout << "level " << this->level << endl; 
    }
};

class Mysort{
    static void sortQuick() {
        cout << "sort quick" << endl;
    }
    static void sortSelect() {
        cout << "sort select" << endl;
    }
    static void sortInsert() {
        cout << "sort insert" << endl;
    }
};
//int People::s_count = 123;
People* People::people = nullptr;//启动时直接实例化
int People::s_total = 123;
int main() {
    People* p = People::create();
    cout << sizeof(People) << " " << People::s_count << endl;

    People::release(p);
    cout << endl;
    cout << "instance = " << People::getInstance() << endl;
    cout << "instance = " << People::getInstance() << endl;
    cout << "instance = " << People::getInstance() << endl;
    cout << "instance = " << People::getInstance() << endl;
    People::getInstance()->addAge();
    return 0;
}
