/*************************************************************************
	> File Name: observer.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Aug 2022 08:45:41 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
class Subject;
class AbstractObserver{
public:
    AbstractObserver(string name):_name(name){}
    virtual ~AbstractObserver(){}
    virtual void update(Subject* p) = 0;
    virtual const string& getName() const{return _name;}
protected:
    string _name;
};

class observerA : public AbstractObserver{
public:
    observerA(string s):AbstractObserver(s) {}
    ~observerA(){}

    void update(Subject* p) override{
        cout << "update observerA name = " << _name << "address = " << this << endl;
    }
};
class observerB : public AbstractObserver{
public:
    observerB(string s):AbstractObserver(s) {}
    ~observerB(){}
    void update(Subject* p) override{
        cout << "update observerB name = " << _name << "address = " << this << endl;
    }
};

class Subject{
protected:
    map<string, vector<AbstractObserver*>> _observers;
public:
    void addObserver(AbstractObserver* p) {
        auto arr = _observers.find(p->getName());
        if (arr != _observers.end()) {
            _observers[p->getName()].push_back(p);
        } else {
            vector<AbstractObserver*> v;
            v.push_back(p);
            _observers[p->getName()] = v;
        }
    }

    void notify(string s) {
        if (_observers.find(s) == _observers.end()) {
            cout << "not found any observer" << endl;
        }

        for (auto x : _observers[s]) {
            x->update(this);
        }
    }
};

int main() {
    Subject subject;
    AbstractObserver* p1 = new observerA("abc");
    AbstractObserver* p2 = new observerB("abc");
    AbstractObserver* p3 = new observerA("abc123");
    AbstractObserver* p4 = new observerB("abc123");
    AbstractObserver* p5 = new observerA("abcd");
    AbstractObserver* p6 = new observerB("abcd");
    AbstractObserver* p7 = new observerA("abc555");
    AbstractObserver* p8 = new observerB("abc555");
    AbstractObserver* p9 = new observerA("a");

    subject.addObserver(p1);
    subject.addObserver(p2);
    subject.addObserver(p3);
    subject.addObserver(p4);
    subject.addObserver(p5);
    subject.addObserver(p6);
    subject.addObserver(p7);
    subject.addObserver(p8);

    cout << "----------abc-----------\n";
    subject.notify("abc");
    cout << "----------abc123-----------\n";
    subject.notify("abc123");
    cout << "----------abcd-----------\n";
    subject.notify("abcd");
    cout << "----------abc555-----------\n";
    subject.notify("abc555");
    cout << "----------a-----------\n";
    subject.notify("a");

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete p7;
    delete p8;
    delete p9;
    return 0;
}
