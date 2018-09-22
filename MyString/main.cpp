//
//  main.cpp
//  MyString
//
//  Created by cmm on 2018/9/23.
//  Copyright © 2018年 bingyan. All rights reserved.
//  数据结构之字符串的实现
//

#include <iostream>
#include <string>
#include <cstring>
#include "MyString.h"
using namespace std;

int main(int argc, const char * argv[]) {
//    string s1, s2("nihao"), s3;
//    char* str1 = new char[30];
//    char* str2 = "nihao";
//    strcat(str1, str2);
//    cout<<s1+s2<<str1<<endl;

    MyString mystr1 = "hello";
    MyString mystr2 = " world";
    MyString mystr3;
    mystr3 = (mystr1+mystr2)+" !";
    cout<<mystr3<<endl;
    return 0;
}
