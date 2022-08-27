/*************************************************************************
	> File Name: userInfo.h
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Aug 2022 10:45:58 PM CST
 ************************************************************************/

#ifndef _USERINFO_H
#define _USERINFO_H
#include "common/marco.h"
#include <string.h>
class UserInfo {
    private:
        GETSETVAR(int, user_id);
        GETSETSTR(256, user_name);
        GETSETSTR(256, nick_name);
        GETSETVAR(int, reg_time);
        GETSETVAR(int, from);
        GETSETVAR(int, login_time);
        GETSETVAR(int, last_login_time);
        GETSETVAR(int, fresh_time);
        GETSETSTR(256, password);
        GETSETVAR(int, logout_time);
        GETSETVAR(int, db_flag);
};
#endif
