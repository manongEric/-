/*************************************************************************
	> File Name: Socket.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Aug 2022 06:57:36 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include "Socket.h"
Config config;
using namespace std;

int SspSocket:: Init() {
    config.ReadConfig();
}
int SspSocket::SocketInit() {
    
    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(config.socket_port());
    server_addr.sin_addr.s_addr = inet_addr(config.socket_addr());

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sock, 10000);
    return 0;
}
int SspSocket::SocketAccept() {
    if (accept_flag == 1) 
        return 0;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);
    accept_flag = 1;
    return 0;
}
//希望不阻塞
int SspSocket::SocketCheckRecv() {
    //struct sockaddr_in client_addr;
    //socklen_t client_addr_size = sizeof(client_addr);
    //client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);
    
    if (accept_flag == 0)
        return -1;
    int ret = recv(client_sock, recv_buffer, 10240, 0);
    if (ret > 0)
        return 0;
    else 
        return -1;
    return 0;
}
int SspSocket::SocketSend(int send_size) {
    int ret = send(client_sock, send_buffer,send_size, 0);
    if (ret < 0) {
        ClientClose();
        return -1;
    }
    return 0;
}
int SspSocket::ClientClose() {
    close(client_sock);
    return 0;
}
int SspSocket::ServerClose() {
    close(server_sock);
    return 0;
        
}
int SspSocket::GetCmdId() {
    int ret = 0;
    ret = ret = (recv_buffer[0] - '0') * 100 + (recv_buffer[1] - '0') * 10 + (recv_buffer[2] - '0');
    return ret;
}

int SspSocket::SetCmdId(int CmdId) {
    int cmd1, cmd2, cmd3;
    cmd3 = CmdId % 10;
    CmdId /= 10;
    cmd2 = CmdId % 10;
    cmd1 = CmdId / 10;
    send_buffer[0] = cmd1 + '0';
    send_buffer[1] = cmd2 + '0';
    send_buffer[2] = cmd3 + '0';
    return 0; 
    
}

char * SspSocket::GetRegUserName() {
    strncpy(user_name, recv_buffer + 3, 8);
    user_name[8] = '\0';
    return user_name;
}
char* SspSocket::GetRegPassword() {
    strncpy(password, recv_buffer + 11, 8);
    password[8] = '\0';
    return password;
}
char* SspSocket::GetLoginUserName() {
    return GetRegUserName();
}

char* SspSocket::GetLoginPassword(){
    return GetRegPassword(); 
}
int SspSocket::SetRet(int ret) {
    sprintf(send_buffer + 3, "%d", ret);
}
int SspSocket::GetAddFriendUserId() {
    int ret = 0;
    int offset = 3;
    for (int i = 0; i < 8; i++) {
        ret = ret * 10 + (recv_buffer[offset + i] - '0');
    }

    return ret;
}

int SspSocket::GetAddFriendOtherId() {
    int ret = 0;
    int offset = 3 + 8;
    for (int i = 0; i < 8; i++) {
        ret = ret * 10 + (recv_buffer[offset + i] - '0');
    }
    return ret;
}
int SspSocket::GetPhotoUserId() {
    return GetAddFriendUserId();
}
int SspSocket::SetPhotoUserId(int publisher) {
    int offset = 7;
    for (int i = 0; i < 8; i++) {
        int m = publisher % 10;
        publisher /= 10;
        send_buffer[15 - i] = m + '0';
    }
    return 0;
}

int SspSocket::GetMessageUserId() {
    return GetAddFriendUserId();
}

int SspSocket::SetMessageInfo(int offset, int message_id, const char * content) {
    int offset_in = 3 + 4;
    int offset_mess = offset_in + offset * (8 + 1024);
    //Set message_id
    for (int i = 0; i < 8; i++) {
        send_buffer[offset_mess + 8 - i] = message_id % 10 + '0';
        message_id = message_id / 10;
    }
    strncpy(send_buffer + (offset_mess + 8), content, 1024);
    return 0;
}
