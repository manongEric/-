/*************************************************************************
	> File Name: Socket.h
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Aug 2022 06:54:39 PM CST
 ************************************************************************/

#ifndef _SOCKET_H
#define _SOCKET_H
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include "Config.h"
class SspSocket{
public:
    int server_sock;
    struct sockaddr_in server_addr;


    int client_sock;
    struct sockaddr_in client_addr;

    int accept_flag = 0;
    char recv_buffer[10240];
    char send_buffer[10240];
    int SocketInit();
    char user_name[256];
    char password[256];
    Config config;
    int Init();
    int SocketAccept();
    int SocketCheckRecv();
    int SocketSend(int send_size);
    int ClientClose();
    int ServerClose();
    int GetCmdId();
    int SetCmdId(int CmdId);
    int SetRet(int ret);
    char* GetRegUserName();
    char* GetRegPassword();
    char* GetLoginUserName();
    char* GetLoginPassword();
    int GetAddFriendUserId();
    int GetAddFriendOtherId();
    int GetPhotoUserId();
    int SetPhotoUserId(int publisher);
    int GetMessageUserId();
    int SetMessageInfo(int offset, int message_id, const char* content);
};
#endif
