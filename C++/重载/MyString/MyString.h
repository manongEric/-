/*************************************************************************
	> File Name: MyString.h
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2022 11:28:58 PM CST
 ************************************************************************/

#ifndef _MYSTRING_H
#define _MYSTRING_H
#include<iosttream>
#include<cstring>
namespace Eric{
    class MyString{
    private:
        char* Data;
        int Length;
        int Capcity;
            
        static void appendString(MyString*, const char*);
        static void copyString(Mystring*, const char*);
        void init();
        static bool expand(MyString*);
        const static int ExpandSize = 1024;

    public:
        Mystring();
        MyString(const char *);
        MyString(const MyString&);
        ~MyString();
        void operator=(const MyString&);
        MyString operator+(const MyString&);
        char& operator[](int index);

        MyString& operator+=(const char*);
        MyString& operator+=(const Mystring&);
        MyString& operator+=(const std::string&);

        inline int size() {return Length;};
        int capcity() {return Capcity;};

        void push_back(const char ch);
        void pop_back();
        void swap(MyString& str);

        friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
            os << str.Data;
            return os;
        }
        friend std::istream& operator>>(std::istream& is, const MyString& str) {
            is >> str.Data;
            str.Length = strlen(str.Data);
        }

    };
}
#endif
