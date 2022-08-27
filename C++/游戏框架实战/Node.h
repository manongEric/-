/*************************************************************************
	> File Name: kkbNode.h
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Aug 2022 11:01:09 PM CST
 ************************************************************************/

#ifndef _NODE_H
#define _NODE_H
#include<vector>
#include<string>
#include "Marco.h"
#include<string>
#include<algorithm>
NS_KKB_BEGIN

class Render;
class Node{
public:
    Node();
    ~Node();
    virtual bool init(){return true;}
public:
    virtual Node* getChildByName(const std::string& name) const;
    template<typename T>
    T getChildByName(const std::string& name) const {return static_cast<T>(getChildByName(name));}

    virtual Node* getChildByTag(int tag) const;
    template<typename T>
    T getChildByTag(int tag) const {return static_cast<T>(getChildByTag(tag));}

    virtual void addChild(Node* child, int localZOrder = 0, int tag = 0);
    virtual void removeChild(Node* child);
    virtual void removeChildByName(std::string& name);
    virtual void removeChildByTag(int tag);

    void sortAllChildren();

    //启动调度update
    void scheduleUpdate(void); //根据每一帧渲染游戏画面，更新物体在游戏位置，调用时，会把node插入schedule中，shedule会回调node的update方法
    void unscheduleUpdate(void);
    void resume();
    void pause();
    virtual void onEnter();//针对游戏初始进入，第一次被渲染
    virtual void onExit();//结点被删除

    virtual void visit(Render* render);//进入结点渲染自己和自己孩子的结点
    virtual void draw(Render* render);//绘制当前结点
    virtual void update(float dt);
public:
    template<typename _T> inline
    static void sortNodes(std::vector<_T*>& nodes) {
        static_assert(std::is_base_of<Node, _T>::value, "Node::sortNodes : only accept Derived");

        std::sort(std::begin(nodes), std::end(nodes), [](_T* n1, _T* n2) {
            return n1->_localZOrder < n2->_localZOrder;
        });
    }

public:
    virtual void setName(const std::string& name) {_name = name;}
    virtual const std::string getName() const{return _name;}
    virtual void setTag(int tag) {_tag = tag;}
    virtual int getTag(){return _tag;}
    virtual void setVisible(bool visible) {_visible = visible;}
    virtual bool isVisible() const {return _visible;}
    virtual void setLocalZOrder(int tag) {_tag = tag;}
    virtual int getLocalZOrder()const {return _tag;}
protected:
    std::string _name;
    int _tag;
    bool _visible;
    int _localZOrder;//判断元素在父节点的左右子树
    float _x, _y;
    bool _reorderChildDirty;//插入子结点时，标记字结点数据为脏数据，渲染时需要重新排序

    std::vector<Node*> _children;
    Node* _parent;
};
NS_KKB_END
#endif
