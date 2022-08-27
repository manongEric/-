/*************************************************************************
	> File Name: messageManager.h
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Aug 2022 11:23:13 PM CST
 ************************************************************************/

#ifndef _MESSAGEMANAGER_H
#define _MESSAGEMANAGER_H
#include "common/marco.h"
#include "MessageInfo.h"

class MessageManager {
private:
    MessageInfo messages_[256];
    GETSETVAR(int, message_count)
public:
    void Start();
    void Proc();
    void Shutdown();
    void Restart();
public:
    MessageInfo* GetMessage(int user_id, int message_id);
    MessageInfo* GetMessage(int message_id);
    int PublishMessage(MessageInfo message);
    int DeleteMessage(int message_id);
};
#endif
