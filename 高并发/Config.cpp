/*************************************************************************
	> File Name: Config.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Aug 2022 07:09:44 PM CST
 ************************************************************************/

#include<iostream>
#include "Config.h"
#include<string.h>


int Config::ReadConfig() {
    FILE* f = fopen("config.ini", "r");
    if (f = NULL) {
        return -1;
    }
    while(1) {
        char config_line[256];
        if (fscanf(f, "%s", config_line) == EOF) {
            break;
        }
        if(strstr(config_line, "socket_port") != NULL) {
            int port = sscanf(config_line, "socket_port=%d", &port);
            set_socket_port(port);
            //socket_port = port;
            printf("port:%d\n", port);
        }
        if (strstr(config_line, "socket_addr") != NULL) {
            char scaddr[256];
            sscanf(config_line, "socket_addr%s", scaddr);
            set_socket_addr(scaddr);
//            strncpy(socket_addr, scaddr, 256);
            printf("addr:%s\n", scaddr);
        }
    }
    fclose(f);
    return 0;
}
