/*************************************************************************
	> File Name: userManager.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Aug 2022 08:22:10 PM CST
 ************************************************************************/

#include<iostream>
#include "userManager.h"
#include "common/ret_value.h"



int userManager::Start(){//读写DB
    set_cur_user_id(10001);
    set_user_count(0);
    return SUCCESS;
}

int userManager::Proc() {
    return SUCCESS;
}

int userManager::Restart() {
    return SUCCESS;
}

int userManager::Shutdown() {
    return SUCCESS;
}

int userManager::CreateUser(const char* user_name, const char* password, int from, int reg_time)  {
    for (int i = 0; i < user_count_; i++) {
        if (strcmp(users_[i].user_name(), user_name) == 0) 
            return USER_EXIST;
    }
    if (user_count_ < 10239) {
        users_[user_count_].set_user_id(cur_user_id());//User id需要一个落地，从文件或数据库读，否则刷新
        users_[user_count_].set_user_name(user_name);
        users_[user_count_].set_password(password);
        users_[user_count_].set_from(from);
        users_[user_count_].set_reg_time(reg_time);

        users_[user_count_].set_db_flag(FLAG_INSERT);
        user_count_++;
    }
    set_cur_user_id(cur_user_id() + 1);
}

int userManager::DeleteUser(int user_id) {
    for (int i = 0; i < user_count_; i++) {
        if (users_[i].user_id() == user_id) {
            users_[i].set_db_flag(FLAG_DELETE);
            return SUCCESS;
        }
    }
    return USER_NOT_EXIST;
};

int userManager::CheckExist(int user_id) {
    for (int i = 0; i < user_count_; i++) {
        if (users_[i].user_id() == user_id) {
            return USER_EXIST;
        }
    }    
    return USER_NOT_EXIST;
}

UserInfo* userManager::GetUser(int user_id) {
    for (int i = 0; i < user_count_; i++) {
        if (users_[i].user_id() == user_id) {
            return &users_[i];
        }
    }
    return NULL;
}

int userManager::LoginCheck(const char* user_name, const char* password) {
    for (int i = 0; i < user_count_; i++) {
        if (strcmp(users_[i].user_name(), user_name) == 0) {
            if (strcmp(users_[i].password(), password) == 0) {
                return SUCCESS;
            } else 
                return WRONG_PASSWORD;
        } 
             
    }
    return USER_NOT_EXIST;
}

int userManager::UserLogout(int user_id, int time_now) {
    for (int i = 0; i < user_count_; i++) {
        if (users_[i].user_id() == user_id) {
            users_[i].set_logout_time(time_now);
            users_[i].set_db_flag(FLAG_UPDATE);
        }
        return SUCCESS;
    }
    return USER_NOT_EXIST;
}

int userManager::UpdateLoginTime(int user_id, int time_now) {
    UserInfo* user = GetUser(user_id);
    if (user == NULL)
        return USER_NOT_EXIST;
    user->set_login_time(time_now);
    user->set_db_flag(FLAG_UPDATE);
}
int userManager::GetUserIdByUserName(const char* user_name) {
    for (int i = 0; i < user_count_; i++) {
        if (strcmp(users_[i].user_name(), user_name) == 0) {
            return users_[i].user_id();
        }
    }
    return USER_NOT_EXIST;
}
