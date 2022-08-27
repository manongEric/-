/*************************************************************************
	> File Name: command.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Aug 2022 10:10:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Receiver{
public:
    Receiver(){}
    virtual ~Receiver(){}

    virtual void operator()(){
        cout << "Excute Command" << endl;
    }
};

class Receiver2 : public Receiver{
public:
    void operator()() override{
        cout << "Excute Command2" << endl;
    }
};

class Command{
public:
    Command() = delete;
    Command(Receiver* p) : _receiver(p){}
    virtual ~Command(){}

    virtual void doCommand(int) = 0;
protected:
    Receiver* _receiver;
};

class CommandA : public Command{
public:
    CommandA() = delete;
    CommandA(Receiver* p) : Command(p) {}
    CommandA(Receiver* p1, Receiver2* p2) : Command(p1), _receiver2(p2) {
        
    }
    void doCommand(int n) override{
        if (n == 1)
            (*_receiver)();
        else 
            (*_receiver2)();
    }

protected:
    Receiver2* _receiver2;
};

class Invoker{
public:
    Invoker():_command(nullptr) {}
    virtual ~Invoker(){}

    void setCommand(Command* p) {
        _command = p;
    }

    void excuteCommand(int n) {
        if (_command) _command->doCommand(n);
    }

private:
    Command* _command;
};

int main() {
    Invoker* invoker = new Invoker();
    Receiver* receiver = new Receiver();
    Receiver2* receiver2 = new Receiver2();
    Command *command = new CommandA(receiver, receiver2);

    invoker->setCommand(command);
    invoker->excuteCommand(1);
    invoker->excuteCommand(2);

    delete command;
    delete receiver;
    delete receiver2;
    delete invoker;




    return 0;
}
