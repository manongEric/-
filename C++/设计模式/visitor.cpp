/*************************************************************************
	> File Name: visitor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Aug 2022 11:55:22 PM CST
 ************************************************************************/

#include<string>
#include<iostream>
using namespace std;

class Node;
class Visitor{
public:
    virtual ~Visitor(){}
    virtual void visit(Node* node) = 0;
};

class Node{
public:
    virtual ~Node(){}
    virtual void accept(Visitor* visitor) = 0;
};

class NodeA : public Node{
    friend class VisitorA;
public:
    NodeA(){
        s = "Hello A !";
    }
    void accept(Visitor* visitor) override{
        visitor->visit(this);
    }
private:
    string s;
};

class NodeB : public Node{
    friend class VisitorB;
public:
    NodeB(){
        s = "Hello B !";
    }
    void accept(Visitor* visitor) override{
        visitor->visit(this);
    }
private:
    string s;
};

class VisitorA : public Visitor{
public:
    void visit(Node* node) override{
        NodeA* p = dynamic_cast<NodeA*>(node);
        if (p)
            cout << "Node A  = " << p->s.c_str() << endl;
    }
};
class VisitorB : public Visitor{
public:
    void visit(Node* node) override{
        NodeB* p = dynamic_cast<NodeB*>(node);
        if (p)
            cout << "Node B  = " << p->s.c_str() << endl;
    }
};

int main() {
    Node* p1 = new NodeA();
    Node* p2 = new NodeB();

    Visitor* p3 = new VisitorA();
    Visitor* p4 = new VisitorB();

    p1->accept(p3);
    p2->accept(p4);


    delete p1;
    delete p2;
    delete p3;
    delete p4;


    return 0;
}
