/*************************************************************************
	> File Name: Photo.h
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Aug 2022 11:31:26 PM CST
 ************************************************************************/

#ifndef _PHOTO_H
#define _PHOTO_H
#include "common/marco.h"
#include <string.h>
class Photo {
    GETSETVAL(int, user_id);
    GETSETVAL(int, last_publisher);//上一次发消息的人  快照
};
#endif
