/*************************************************************************
	> File Name: bridge.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Jul 2022 04:38:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Soft {
public:
    Soft(){}

    virtual ~Soft(){}

    virtual void run() = 0;
};
class Phone{
public:
    Phone() = default;
    virtual ~Phone(){}

    virtual void runSoft() = 0;

    void installSoft(Soft* soft) {
        _soft = soft;
    }
protected:
    Soft * _soft;
};
class PhoneA : public Phone{
public:
    virtual void runSoft() override{
        if (_soft) {
            cout << " PhoneA Start launch soft" << endl;
        }else {
            cout << "PhoneA Start launch soft is null" << endl;
        }
    }
};

class PhoneB : public Phone{
public:
    virtual void runSoft() override{
        if (_soft) {
            cout << " PhoneB Start launch soft" << endl;
        }else {
            cout << "PhoneB Start launch soft is null" << endl;
        }
    }
};

class SoftA : public Soft{
public:
    void run() override{
        cout << "SoftA is running" << endl;
    }
};

class SoftB : public Soft{
public:
    void run() override{
        cout << "SoftB is running" << endl;
    }
};

int main() {
    Soft* pSoft1 = new SoftA();
    Soft* pSoft2 = new SoftB();

    Phone* p1 = new PhoneA();
    Phone* p2 = new PhoneB();

    p1->installSoft(pSoft1);
    p2->installSoft(pSoft2);
    p1->runSoft();
    p2->runSoft();

    delete pSoft1;
    delete pSoft2;
    delete p1;
    delete p2;


    return 0;
}
