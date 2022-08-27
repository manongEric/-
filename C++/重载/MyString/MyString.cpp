/*************************************************************************
	> File Name: MyString.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2022 11:59:29 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include "MyString.h"
using namespace Eric;

void MyString::init(){
    this->Length = 0;
    this->Capacity = ExpandSize;
    this->Data = (char*)malloc(this->Capacity * sizeof(char));
}
bool MyString::expand(MyString* str){
    int exSize = ExpandSize;
    char* p = nullptr;
    while(exSize) {
        p = (char *)realloc(str->data, sizeof(char) * (str->Capacity + exSize));
        if(p != nullptr)
            break;
        exSize /= 2;
    }
    if(p == nullptr)
        return false;
    str->Capacity += exSize;
    str->Data = p;
    return true;
}

void MyString::copyString(MyString* myString, const char* str){
    int strLen = strlen(str);
    while(myString->Capacity <= strLen){
        if(!expand(myString))
            break;
    }
    if(myString->Capacity <= strLen){
        myString->Length = myString->Capacity - 1;
        strncpy(myString->Data, str, myString->Length);
    } else {
        myString->Length = strLen;
        strncpy(myString->Data, str, strLen);
    }
    myString->Data[myString->Length] = '\0';
}
MyString::MyString(){
    init();
    this->Data[0] = '\0';
}

MyString::MyString(const char* str){
    init();
    copyString(this, str);
}

MyString::MyString(const MyString& str){
    init();
    copyString(this, str.Data);
}

void MyString::operator=(const MyString &str) {//重载=用引用
    copyString(this, str.Data);
}

char& MyString::operator[](int index){
    return this->Data[index];
}

void MyString::push_back(const char ch){
    int len = this->Length + 1;
    while(this->Capacity <= len) {
        if (!expand(this)){
            break;
        }
    }
    if (this->Capacity > len){
        this->Data[this->Length++] = ch;
        this->Data[this->Length] = '\0';
    }
}

void MyString::pop_back(){
    if (this->Length > 0){
        this->Data[--this->Length] = '\0';
    }
}
