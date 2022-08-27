/*************************************************************************
	> File Name: lesson2-fstream.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Jul 2022 05:45:41 PM CST
 ************************************************************************/

#include<fstream>
#include<iostream>
#include<math.h>
using namespace std;


void testif(){
    ifstream fin;
    fin.open("kaikeba.txt", ios::out);
    if (!fin){//打开失败为0
        cout << "文件打开失败, state = " << fin.rdstate() << endl;
    } 
    else {
        string str;
        while(!fin.rdstate()) {
            getline(fin, str);//fin 对象，指向字符地址的指针
            cout << str << endl;
        }
        fin.close();
    }
}

void testof(string txt){
    ofstream fout;
    fout.open("kaikeba.txt", ios::out | ios::app);//app默认创建
    if (!fout){
        cout << "fail open" << endl;
    } else {
        fout << txt; // 像文件写入数据
        fout.close();
    }
}

int main(){
    testof("123");
    testof("456");
    testof("789");
    testif();
    
    double a = fmod(3.6 ,0.3);
    cout << a << endl;
    return 0;
}
