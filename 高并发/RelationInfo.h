/*************************************************************************
	> File Name: RelationInfo.h
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Aug 2022 10:53:33 PM CST
 ************************************************************************/

#ifndef _RELATIONINFO_H
#define _RELATIONINFO_H
#include "common/marco.h"
#include <string.h>
class RelationInfo {
    GETSETVAR(int ,user_id)
    GETSETVAR(int, friend_count)//实际用的数量,mZ
    int friend_list_[10240];
    int black_list_[10240];
    GETSETVAR(int, black_count)
public:
    int CheckFriend(int other_id);
    int CheckBlack(int other_id);
    //添加好友对应到friendlist上，RelationManager 无法直接修改Info内容
    int AddFriend(int other_id);
    int AddBlack(int other_id);
    int DeleteFriend(int other_id);
    int DeleteBlack(int other_id);
    int GetFriendByIndex(int index);
    int GetBlackByIndex(int index);
};
#endif
