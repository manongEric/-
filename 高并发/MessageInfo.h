/*************************************************************************
	> File Name: MessageInfo.h
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Aug 2022 11:32:58 PM CST
 ************************************************************************/

#ifndef _MESSAGEINFO_H
#define _MESSAGEINFO_H
#include "common/marco.h"
#include <string.h>

class MessageInfo {
    GETSETVAR(int, user_id)
    GETSETVAR(int, message_id)
    GETSETVAR(int, publish_time)
    GETSETSTR(1024, content)
};
#endif
