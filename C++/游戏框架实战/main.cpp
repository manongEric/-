/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Aug 2022 07:28:38 PM CST
 ************************************************************************/

#include<iostream>
#include "Node.h"
#include "Marco.h"
USING_NS_KKB;

int main() {
    Node* node = new Node();
    for (int i = -2; i <= 2; i++) {
        auto p = new Node();
        p->setName("Node - " + std::to_string(i));
        node->addChild(p, i, i);
    }

    node->visit(nullptr);


    return 0;
}
