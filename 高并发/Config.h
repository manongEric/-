/*************************************************************************
	> File Name: Config.h
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Aug 2022 07:08:14 PM CST
 ************************************************************************/

#ifndef _CONFIG_H
#define _CONFIG_H
#include "common/marco.h"
class Config {
    GETSETVAR(int, socket_port)
    GETSETSTR(256, socket_addr)
public:
    int ReadConfig();
};
#endif
