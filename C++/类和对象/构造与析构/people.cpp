/*************************************************************************
	> File Name: people.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Jun 2022 07:01:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class People {
protected :
    string name;
    double weight;
    double height;
    int age;
public :
    People() {
        cout << "default constructor !" << endl;
    }
    ~People() {
        cout << "destructot!" << endl;
    }
    People(int _age) :
    age(_age), name(""), weight(0), height(0){
        
    }
    People(const People&p) :
    age(p.age), name(p.name), weight(p.weight), height(p.height) {
        cout << "copy constructor" << endl;
    }
   /* People(string name, double weight, double height, int age) {
        this->name = name;
        this->weight = weight;
        this->height = height;
        this->age = age;
    }*/
    People(string _name, double _weight = 0, double _height = 0, int _age = 0) :
    name(_name), weight(_weight), height(_height), age(_age) {
    //    cout << "constructor!" << endl;
        cout << "master constructor" << endl;
    }
    void say(string word) {
        cout << "name = " << name << " age = " << age << " weight = " << weight << " height = " << height<< endl;
    }

};

void* operator new(size_t size) {
    cout << "operator new = " << size << endl;
    void *p = malloc(size);
    return p;
}
void operator delete(void *p) {
    if(p) free(p);
    cout << "operator delete " << endl;
}

const int size = 1024 * 1024;
char *buff = new char[size];
int main() {
    People *p = new People("master", 120, 180, 18);
    delete p;

    People *p1 = new(buff) People("master1", 120, 180, 18);//p1指针指向的类在buff内存中
    p1->~People();//显示调用析构，p1指向buff中的people类空间,动态分配的空间是buff而不是p1；
    delete buff;
    //People p1("ming", 120, 180, 18);
    //p1.say("ming");
    //People master(p1);//拷贝构造
    //master.say("");
   // People p2("meng");
   // p2.say("meng");
    //People p3(18);
   // p3.say("");
    //People *ptr = new People();
    //delete ptr;
    return 0;
}
