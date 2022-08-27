/*************************************************************************
	> File Name: marco.h
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Aug 2022 10:35:45 PM CST
 ************************************************************************/

#ifndef _MARCO_H
#define _MARCO_H
#include <cstring>
#define GETSETVAR(type, name) \
    private: \
        type name##_;\
    public:\
        const type& name() const{\
            return name##_;\
        }\
        void set_##name(const type& value) {\
            name##_ = value;\
        }

#define GETSETSTR(size, name) \
        private :\
            char name##_[size];\
        public: \
        const char* name() const{\
            return name##_; \
        } \
        void set_##name(const char* value) {\
            strncpy(name##_, value, size);\
        }
    
#endif
