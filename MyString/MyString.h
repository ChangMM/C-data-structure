//
//  MyString.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/23.
//  Copyright © 2018年 bingyan. All rights reserved.
//  数据结构之字符串的实现
//

#ifndef MyString_h
#define MyString_h
#include<iostream>
#include <cstring>

using namespace std;
class MyString{
private:
    unsigned int _length;
    char* _p;
    void _copy(const char* _pstr);
    void _copy(const MyString& _str);
public:
    MyString():_p(NULL), _length(0){};
    MyString(const MyString& _str);
    MyString(const char* _pstr);
    MyString(char c, unsigned int n);
    ~MyString();

    bool empty() const; // 字符串是否为空
    unsigned int length() const;

    // 获取字符串内的存储指针
    const char* c_str() const;

    // 一些运算符重载
    char& operator[](unsigned int i);  // 返回值类型应该是 char& 而不是 char
    MyString& operator=(const MyString& _str);
    MyString& operator=(const char* _pstr);
    MyString operator+(const MyString& _str);
    MyString operator+(const char* _pstr);
    friend MyString operator+(const char* _pstr, const MyString& _str);  // 需要重载为友元函数

    //一些字符串的操作
    MyString substr(const MyString& _str);
    bool campare(const MyString& _str);
    bool find(const MyString& _str, unsigned int start = 0);
    bool find(char c, unsigned int start = 0);
    void replace(unsigned int start, unsigned int len, const MyString& _str);
    void insert(unsigned int start, const MyString& _str);
    void erase(unsigned int start, unsigned int len);
};

const char* MyString::c_str() const{
    return _p;
}

void MyString::_copy(const char* _pstr){
    // 并未判断 _pstr 长度超过 unsigned int 范围的情况
    if(_pstr != NULL){ // 这一步需要判断
        unsigned int len = unsigned(strlen(_pstr));
        _p = new char[len + 1];
        _length = len;
        strcpy(_p, _pstr);  // 也可用 memcpy(_p, _pstr, len*sizeof(char)); 来代替
    } else {
        _p = NULL;
        _length = 0;
    }
}

void MyString::_copy(const MyString& _str){
    if(_str.c_str() != NULL){ // 这一步需要判断
        unsigned int len = _str.length();
        _p = new char[len + 1];
        _length = len;
        strcpy(_p, _str.c_str());
    } else {
        _p = NULL;
        _length = 0;
    }
}

MyString::MyString(const MyString& _str){
    _copy(_str);
}

MyString::MyString(const char* _pstr){
    _copy(_pstr);
}

MyString::MyString(char c, unsigned int n){
    _p = new char[n + 1];
    _length = n;
    for (unsigned int i=0; i<n; i++){
        _p[i] = c;
    }
    _p[n] = '\0';
}


MyString::~MyString(){
    if(_p != NULL){
        delete []_p;
    }
}

bool MyString::empty() const{
    return _length == 0;
}

unsigned int MyString::length() const{
    return _length;
}

char& MyString::operator[](unsigned int i){
    if(i>=_length){
        cerr<<"out of range"<<endl;
        exit(0);
    }
    return _p[i];
}

MyString& MyString::operator=(const char *_pstr){
    if(_p != NULL){
        delete [] _p;
    }
    _copy(_pstr);
    return *this;
}

MyString& MyString::operator=(const MyString &_str){
    if(_p != _str.c_str()){ // 这一个尤其重要
        if(_p != NULL){
            delete [] _p;
        }
        _copy(_str);
    }
    return *this;
}

MyString MyString::operator+(const MyString& _str){
    const char* _pstr = _str.c_str();
    MyString temp = *this + _pstr;
    return temp;
}

MyString MyString::operator+(const char* _pstr){
    MyString temp;
    if(_pstr==NULL && _p!=NULL){
        temp = *this;
    } else if(_pstr!=NULL && _p==NULL){
        temp = _pstr;
    } else if(_pstr!=NULL && _p!=NULL){
        char * c_temp = new char[_length + strlen(_pstr) + 1];
        strcat(c_temp, _p);
        strcat(c_temp, _pstr);
        temp = c_temp;
    }
    return temp;
}

// 友元函数的声明
MyString operator+(const char* _pstr, const MyString& _str){
    MyString temp;
    temp = temp + _pstr;
    temp = temp + _str.c_str();
    return temp;
}

// 重载流操作运算符
ostream& operator<<(ostream& o, const MyString& _str){
    if(_str.c_str() != NULL){
        o<<_str.c_str();
    }
    return o;
}

istream& operator>>(istream& is, MyString& _str){
    char *_pstr = new char[50];
    is>>_pstr;
    _str = _pstr;
    return is;
}

#endif /* MyString_h */
