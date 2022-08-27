/*************************************************************************
	> File Name: PhotoManager.h
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Aug 2022 06:43:38 PM CST
 ************************************************************************/

#ifndef _PHOTOMANAGER_H
#define _PHOTOMANAGER_H
#include "PhotoInfo.h"
class PhotoManager {
private:
    PhotoInfo photos_[10240];
    GETSETVAR(int, photo_count)
public:
    void Start();
    void Proc();
    void Shutdown();
    void Restart();
public:
    PhotoInfo* GetPhoto(int user_id);
    int UpdatePhoto(int user_id, int publisher_id, int publish_time, int public_message_id);
};
#endif
