/*************************************************************************
	> File Name: Node.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Aug 2022 09:53:44 PM CST
 ************************************************************************/

#include<iostream>
#include "Node.h"
#include<algorithm>
#include "Marco.h"
NS_KKB_BEGIN

Node::Node(){
    KKBLOG("构造Node  --- address = %p \n", this);    
}
Node::~Node() {
    KKBLOG("析构Node --- address = %p; name = %s\n", this, _name.c_str());
}

Node* Node::getChildByName(const std::string& name) const{
    for (const auto& child : _children) {
        if (child->_name.compare(name) == 0) {
            return child;
        }
    }
    return nullptr;
}
Node* Node::getChildByTag(int tag) const{
    for (const auto& child : _children) {
        if (child->_tag == tag) {
            return child;
        }
    }
    return nullptr;
}

void Node::addChild(Node* child, int localZOrder, int tag) {
    child->_parent = this;
    _children.push_back(child);
    child->_tag = tag;
    child->_localZOrder = localZOrder;
    _reorderChildDirty = true;
}

void Node::removeChild(Node* child) {
    if (_children.empty()) return;
    auto it = std::find(std::begin(_children), std::end(_children), child);
    if (it != _children.end()) {
        _children.erase(it);
    }
}

void Node::removeChildByName(std::string& name) {
    for (auto it = std::begin(_children); it != std::end(_children); it++) {
        if ((*it)->_name.compare(name) == 0) {
            _children.erase(it);
            break;
        }
    }
}


void Node::removeChildByTag(int tag) {
    for (auto it = std::begin(_children); it != std::end(_children); it++) {
        if ((*it)->_tag == tag){
            _children.erase(it);
            break;
        }
    }
}

void Node::sortAllChildren(){
    if (_reorderChildDirty) {
        sortNodes(_children);
        _reorderChildDirty = false;
    }
}
void Node::scheduleUpdate(void) {
    
}
void Node::unscheduleUpdate(void) {

}
void Node::resume() {
    
}
void Node::pause() {

}
void Node::onEnter() {
    
}//针对游戏初始进入，第一次被渲染
void Node::onExit() {

}

void Node::visit(Render* render) {
    int i = 0;
    if (!_children.empty()) {
        sortAllChildren();
        for (; i < _children.size(); i++) {
            auto node = _children.at(i);
            if (node && node->_localZOrder < 0) {
                node->visit(render);
            } else{
                break;
            }
        }
        this->draw(render);

        for (auto it = _children.begin() + i; it != _children.end(); ++it) {
            (*it)->visit(render);
        }
    } else {
        this->draw(render);
    }
}
void Node::draw(Render* render) {
    KKBLOG("kkbNode--draw ! name = %s \n", _name.c_str());
}
void Node::update(float dt) {
    
}
NS_KKB_END
