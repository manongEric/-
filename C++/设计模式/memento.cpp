/*************************************************************************
	> File Name: memento.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Aug 2022 11:55:06 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct StateInfo{
    int _a;
    int _b;
};
class CareTaker{
public:
    static CareTaker* _instance;
    static CareTaker* instance(){
        if (_instance == nullptr) {
            _instance = new CareTaker();
        }
        return _instance;
    }

    virtual ~CareTaker(){
        for (auto it : _states) {
            delete it;
        }
    }

    void addState(int a, int b) {
        _states.push_back(new StateInfo{a, b});
    }

    StateInfo* getState(int index) {
        if (_states.size() > index) {
            return _states[index];
        }
        return nullptr;
    }
private:
    vector<StateInfo*> _states;
} ;

class Originator{
public:
    Originator():_a(0), _b(0) {

    }
    void setA(int n) {
        _a = n;
        this->saveState();
    }
    void setB(int n) {
        _b = n;
        this->saveState();
    }

    void saveState(){
        CareTaker::instance()->addState(_a, _b);
    }
    void getState(int index) {
        auto p = CareTaker::instance()->getState(index);
        if (p) {
            _a = p->_a;
            _b = p->_b;
        }
    }
    void debug() {
        cout << "a = " << _a << " _b = " << _b << endl;
    } 
private:
    int _a;
    int _b;
};
CareTaker* CareTaker::_instance = nullptr;

int main(){
    Originator* p = new Originator();
    p->setA(1);
    p->setB(1);
    p->setB(123);
    p->setB(1123);
    p->setB(1233323);
    p->setA(1333);
    p->setA(44);
    p->setA(877);
    p->debug();

    cout << "------recover 3----------" << endl;
    p->getState(3);
    p->debug();
    
    delete p;
    return 0;
}
