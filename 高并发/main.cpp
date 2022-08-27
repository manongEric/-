/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Aug 2022 06:35:26 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include "userManager.h"
#include "RelationManager.h"
#include "MessageManager.h"
#include "PhotoManager.h"
#include "Socket.h"
#include "common/proto.h"
#include "common/ret_value.h"
#include<unistd.h>
#include<sys/time.h>

using namespace std;
SspSocket sock;
userManager user_svr;
RelationManager rela_svr;
MessageManager mess_svr;
PhotoManager photo_svr;
int main() {
    user_svr.Start();
    rela_svr.Start();
    mess_svr.Start();
    photo_svr.Start();
    sock.Init();
    sock.SocketInit(); // 监听
    int server_on = 1;
    while(server_on){
        sock.SocketAccept();
        sock.SocketCheckRecv();
        user_svr.Proc();//log message
        rela_svr.Proc();
        mess_svr.Proc();
        photo_svr.Proc();
        int time_now = time(NULL);
        int ret = 0;
        //register request
        //get value from recv_buff
        int cmd_id = sock.GetCmdId();
        switch(cmd_id) {
            case REG_REQ: {
                char* user_name = sock.GetRegUserName();
                char* password = sock.GetRegPassword();

                int user_id = user_svr.GetUserIdByUserName(user_name);
                int ret_value = 0;
                if (user_id == USER_NOT_EXIST) {
                    user_svr.CreateUser(user_name, password, 1, time_now);
                } else {
                    //return user_exist
                    ret_value = USER_EXIST;
                }
                sock.SetCmdId(REG_RSP);
                sock.SetCmdId(cmd_id + 1);
                sock.SetRet(ret_value);
                sock.SocketSend(7);
            }
            break;
            case LOGIN_REQ: {
                char* user_name = sock.GetLoginUserName();
                char* password = sock.GetLoginPassword();
                ret = user_svr.LoginCheck(user_name, password);
                sock.SetRet(ret);
                sock.SetCmdId(cmd_id + 1);
                sock.SocketSend(7);
            }
            break;
            case ADD_FRIEND_REQ:
            {
                int user_id = sock.GetAddFriendUserId();
                int other_id = sock.GetAddFriendOtherId();
                ret = user_svr.CheckExist(user_id);
                if (ret == USER_NOT_EXIST) {
                    //USER_NOT_EXIST
                    sock.SetRet(ret);
                } else {
                    ret = user_svr.CheckExist(other_id);
                    if (ret == USER_EXIST) {
                        rela_svr.AddFriend(user_id, other_id);
                        sock.SetRet(ret);
                    } else {
                        //FRIEND_ID NOT oEXIST
                        sock.SetRet(ret);
                    }
                }
                sock.SetCmdId(cmd_id + 1);
                sock.SocketSend(7);
            }
            break;
            case GET_PHOTO_LIST_REQ: 
            {
                int user_id = sock.GetPhotoUserId();
                user_svr.CheckExist(user_id);
                if (ret == USER_EXIST) {
                    sock.SetRet(SUCCESS);
                    PhotoInfo* photo =  photo_svr.GetPhoto(user_id);
                    if (photo == NULL) {
                        sock.SetPhotoUserId(0);
                    } else {
                        sock.SetPhotoUserId(photo->last_publisher());
                    }
                } else {
                    sock.SetRet(ret);
                }
                sock.SocketSend(15);
            }
            break;
            case GET_MESSAGE_LIST_REQ: 
                {
                    int user_id = sock.GetMessageUserId();
                    ret = user_svr.CheckExist(user_id);
                    if(ret == USER_EXIST) {
                        int message_id[10];// = sock.GetMessageList();
                        int message_list_size = 3;
                        for (int i = 0; i < message_list_size; i++) {
                            MessageInfo* message = mess_svr.GetMessage(user_id, message_id[i]);
                            sock.SetMessageInfo(i, message->message_id(), message->content());
                        }
                    } else {
                        sock.SetRet(ret);
                    }
                    sock.SetCmdId(cmd_id + 1);
                    sock.SocketSend(7 + 3 * (8 + 1024));
                }
            break;
            default:
                break;
        }
        //response register
        //login request
        //response login


        //logout request

        //addfriend
        usleep(5000);//5ms
        }

    user_svr.Shutdown();
    rela_svr.Shutdown();
    mess_svr.Shutdown();
    photo_svr.Shutdown();
    return 0;
}

