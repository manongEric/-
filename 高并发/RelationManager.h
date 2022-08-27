/*************************************************************************
	> File Name: RelationManager.h
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Aug 2022 04:10:20 PM CST
 ************************************************************************/

#ifndef _RELATIONMANAGER_H
#define _RELATIONMANAGER_H
#include "RelationInfo.h"
class RelationManager{
private:
    RelationInfo relations_[10240];
    GETSETVAR(int, relation_count)
public:
    int Start();
    int Proc();
    int Restart();
    int Shutdown();
public:
    int UserRelationInit(int user_id);
    RelationInfo* GetRelation(int user_id);
    int AddFriend(int user_id, int other_id);
    int DelFriend(int user_id, int other_id);
    //ADDBlack
    //DelBlack
};
#endif
