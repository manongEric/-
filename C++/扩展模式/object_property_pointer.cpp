/*************************************************************************
	> File Name: object_property_pointer.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Aug 2022 08:22:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGIN(x) namespace x {
#define END(x) }

BEGIN(test1)
int func(int a, int b) {
    return a + b;
}

class A{
public:
    int func2(int a, int b) {
        return a + b;
    }
    int func3(int a, int b) {
        return a + b * 2;
    }
};

int main() {
    int (*p)(int, int);
    p = func;
    cout << p(3, 4) << endl;
    int (A::*p2)(int, int); //定义成员方法指针方式

    A a;
    cout << "对象调用func2 " << a.func2(3, 4) << endl;
    p2 = &A::func2;
    cout << "成员方法指针绑定成员方法func2 " << (a.*p2)(3, 4) << endl; // p2 = &func2 -> *p2 = func2;
    p2 = &A::func3;
    cout << "成员方法指针绑定成员方法func3 " << (a.*p2)(3, 4) << endl; // p2 = &func2 -> *p2 = func2;


    return 0;
}
END(test1)

BEGIN(test2)
class skill{
public:
    void (skill::*s1)();
    void (skill::*s2)();
    void (skill::*s3)();

    void ranged_attack() {
        cout << "ranged attack" << endl;
        return;
    }   

    void melee_attack() {
        cout << "melee attack" << endl;
        return;
    }

    void FireBall() {
        cout << "file ball" << endl;
        return;
    }

    void Bump(){
        cout << "Bump" << endl;
        return;
    }

    void go_home() {
        cout << "go home" << endl;
        return;
    }
};
class attacker;
class Rule{
public:
    Rule(Rule *next = nullptr):next(next) {}
    virtual void action(attacker* obj) = 0;
public:
    Rule* next;
};
class attacker{
public:
    attacker(string type, Rule *rule_list = nullptr) : 
    type(type), rule_list(rule_list){}
    void attack() {
        cout << "attack : " << endl;
        (s.*s.s1)();
        (s.*s.s2)();
        (s.*s.s3)();
        return;
    }

    void change_hp(int hp) {
        this->hp += hp;
      //  Rule *p = rule_list;
       // while (p) p->action(this), p = p->next;
        return;
    }
public:
    skill s;
    int hp;
    string type;
    Rule *rule_list;
};

class Rule_Hp_LESS_50 : public Rule {
public:
    Rule_Hp_LESS_50() : Rule(nullptr) {}
    virtual void action(attacker* obj) override{
        if (obj->hp < 50) {
            obj->s.s1 = &skill::ranged_attack;
        } else {
            obj->s.s1 = &skill::melee_attack;
        }
        return;
    }
};

attacker* soldier_factory(){
    attacker* obj = new attacker("soldier");
    obj->s.s1 = &skill::melee_attack;
    obj->s.s2 = &skill::Bump;
    obj->s.s3 = &skill::go_home;
    obj->hp = 100;
    return obj;
}

attacker* master_factory(){
    attacker* obj = new attacker("master");
    obj->s.s1 = &skill::ranged_attack;
    obj->s.s2 = &skill::FireBall;
    obj->s.s3 = &skill::go_home;
    obj->hp = 100;
    return obj;
}

attacker* sowar_factory(){
    attacker* obj = new attacker("sowar", new Rule_Hp_LESS_50());
    obj->s.s1 = &skill::melee_attack;
    obj->s.s2 = &skill::FireBall;
    obj->s.s3 = &skill::go_home;
    obj->hp = 100;
    return obj;
}

ostream &operator<<(ostream &out, const attacker& obj) {
    out << obj.type << "[" << obj.hp << "]";
    return out;
}

int main() {
    attacker* arr[6];
    for (int i = 0; i < 6; i++) {
        switch(rand() % 3) {
            case 0: arr[i] = soldier_factory();break;
            case 1: arr[i] = master_factory();break;
            case 2: arr[i] = sowar_factory();break;
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << i << " : " << *arr[i] << endl;//对象
    }
    string op;
    int val, ind;
    while (cin >> op >> ind) {
        switch(op[0]) {
            case '*' :arr[ind]->attack();break;
            case '+' :{
                cin >> val;
                arr[ind]->change_hp(val);
            }break;
            case '-': {
                cin >> val;
                arr[ind]->change_hp(-val);
            }break;
        }
        for (int i = 0; i < 6; i++) {
            cout << i << " : " << *arr[i] << endl;
        }
    }
    
    
    return 0;
}
END(test2)
int main() {
    test2::main();
    return 0;
}
