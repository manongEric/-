/*************************************************************************
	> File Name: userManager.h
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Aug 2022 11:36:39 PM CST
 ************************************************************************/

#ifndef _USERMANAGER_H
#define _USERMANAGER_H
#include "common/marco.h"
#include "userInfo.h"
class userManager{
    UserInfo users_[10240];
    GETSETVAR(int, user_count)
    GETSETVAR(int, cur_user_id)
public:
    //通用进程方法
    int Start();
    int Proc();
    int Restart();
    int Shutdown();
public:
    UserInfo *GetUser(int user_id);
    int CheckExist(int user_id);
    int CreateUser(const char* user_name, const char* password, int from, int reg_time);//把时间传进来，避免中断获取时间，或linux获得文件描述符,传变量节省服务器性能
    int DeleteUser(int user_id);
    int SaveUser();
    int LoginCheck(const char* user_name, const char* password);
    int UserLogout(int user_id, int time_now);
    int GetUserIdByUserName(const char* user_name);
    int UpdateLoginTime(int user_id, int time_now);
   // int UpdateUserLogoutTime(int user_id, int time_now);
    //int UpdateUserFreshTime(int user_id, int time_now);
};
#endif
