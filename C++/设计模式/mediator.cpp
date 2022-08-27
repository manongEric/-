/*************************************************************************
	> File Name: mediator.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Aug 2022 12:46:25 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
class Colleague;
class Mediator {
public:
    virtual void deal(Colleague* ) = 0;
    virtual void setMediator(Colleague* from, Colleague* to) {
        _from = from;
        _to = to;
    }

protected:
    Colleague* _from;
    Colleague* _to;
};

class Colleague{
public:
    Colleague() = delete;
    Colleague(Mediator* p):_mediator(p) {

    }
    virtual ~Colleague(){}
    virtual void send() = 0;
    virtual void receive(string s) = 0;
protected:
    Mediator* _mediator;
};

class ColleagueA : public Colleague{
public:
    ColleagueA(Mediator* p): Colleague(p) {

    }

    void send() override{
        _mediator->deal(this);
    }

    void receive(string s) override{
        cout << s.c_str() << endl;
    }
};
class ColleagueB : public Colleague{
public:
    ColleagueB(Mediator* p): Colleague(p) {

    }

    void send() override{
        _mediator->deal(this);
    }

    void receive(string s) override{
        cout << s.c_str() << endl;
    }
};

class MediatorA : public Mediator{
public:
    void deal(Colleague *p) override{
        if (p == _from) {
            _from->receive("from->to");
        } else {
            _to->receive("to->from");
        }
    }
};

int main() {
    Mediator* mediator = new MediatorA();
    Colleague* p1 = new ColleagueA(mediator);
    Colleague* p2 = new ColleagueB(mediator);

    mediator->setMediator(p1, p2);

    p1->send();
    p2->send();

    delete p1;
    delete p2;
    return 0;
}
