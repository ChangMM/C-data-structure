//
//  LinkList.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/18.
//  Copyright © 2018年 bingyan. All rights reserved.
//  单链表的模板函数
//

#pragma once
#ifndef LinkList_h
#define LinkList_h
#include "stdio.h"
#include <iostream>
#include "ListADT.h"
using namespace std;

template <class T> class Link {
public:
    T data; // 用于保存结点元素的内容
    Link<T> * next; // 指向后继结点的指针
    Link(const T info, const Link<T>* nextValue = NULL) {
        data = info;
        next = nextValue;
    }
    Link(const Link<T>* nextValue) {
        next = nextValue;
    }
};

template <class T> class lnkList : public List<T> {
private:
    Link<T> * head, *tail; // 单链表的头、尾指针
    Link<T> *setPos(const int p); // 第p个元素指针
public:
    lnkList(); // 构造函数
    ~lnkList(); // 析构函数
    bool isEmpty(); // 判断链表是否为空
    void clear(); // 将链表存储的内容清除，成为空表
    int length(); // 返回此顺序表的当前实际长度
    bool appendElement(const T value); // 表尾添加一个元素 value，表长度增 1
    bool insertElement(const int p, const T value); // 位置 p 上插入一个元素
    bool deleteElement(const int p); // 删除位置 p 上的元素，表的长度减 1
    bool getValue(const int p, T& value);   // 返回位置 p 的元素值
    bool getPos(int &p, const T value); // 查找值为 value 的元素
};

template <class T> lnkList<T>::lnkList() {
    head=NULL;
    tail=NULL;
}

template <class T> lnkList<T>::~lnkList() {
    if (head==NULL)
        {
        return;
        }
    Link<T>* cur=head;
    while(cur != NULL) {
        Link<T>* del=cur;
        cur = cur->next;
        delete del;
    }
    delete cur;
    head=NULL;
    tail=NULL;
}

template <class T> Link<T>* lnkList<T>::setPos(const int i) {
    int count=0;
    Link<T>* p=head;  //循链定位，若i为0则定位到第一个结点
    while(p != NULL && count<i) {
        p=p->next;
        count++;
    }
    return p;   //指向结点i
}

template <class T> bool lnkList<T>::insertElement(const int i, const T value) {
    Link<T> *p, *q;
    if ((p=setPos(i-1))==NULL)   //p是位置i结点的前驱
        {
        cout <<  "Insertion point is illegal" << endl;
        return false;
        }
    q = new Link<T>(value, p->next);
    p->next = q;
    if (p==tail)  //插入点在链尾，插入结点成为新的链尾
        {
        tail = q;
        }
    return true;
}

template <class T> bool lnkList<T>::deleteElement(const int i) {
    Link<T> *p, *q;
    if (i==0){  //删除头结点
        q=head;
        head=head->next;
        delete q;
        return true;
    }
    p=setPos(i-1);
    if (p==NULL || p==tail) {  //删除的结点不存在
        cout << "deletion is illegal" << endl;
        return false;
    }
    q=p->next;   //q是真正待删除结点
    if (q==tail)  //待删结点为尾结点，则修改尾指针
        {
        tail = p;
        p->next=NULL;
        }
    else
        p->next=q->next;   //删除结点q并修改链指针
    delete q;
    return true;
}

template <class T> bool lnkList<T>::isEmpty() {
    if (head==NULL) {
        return true;
    }
    else {
        return false;
    }
}

template <class T> void lnkList<T>::clear() {
    if (head==NULL)
        {
        return;
        }
    Link<T>* cur=head;
    while(cur != NULL) {
        Link<T>* del=cur;
        cur = cur->next;
        delete del;
    }
    delete cur;
    head=NULL;
    tail=NULL;
}

template <class T> int lnkList<T>::length() {
    int count=0;
    Link<T>* cur=head;
    while(cur) {
        count++;
        cur = cur->next;
    }
    return count;
}

template <class T> bool lnkList<T>::appendElement(const T value) {
    Link<T>* newLink = new Link<T>(value);
    if (head==NULL) {
        head=newLink;
        tail=head;
    }
    else {
        tail->next = newLink;
        tail=newLink;
    }
    return true;
}

template <class T> bool lnkList<T>::getPos(int& i, const T value) {
    Link<T>* cur=head;
    int count=0;
    while(cur) {
        if (cur->data==value)
            {
            i=count;
            return true;
            }
        cur = cur->next;
        count++;
    }
    cout << "can not find element: " << value << endl;
    return false;
}

template <class T> bool lnkList<T>::getValue(const int i, T& value) {
    int count=0;
    Link<T>* cur=head;  //循链定位，若i为0则定位到第一个结点
    while(cur != NULL && count<i) {
        cur=cur->next;
        count++;
    }
    if (cur==NULL) {
        return false;
    }
    else {
        value = cur->data;
        return true;
    }
}

#endif /* LinkList_h */
