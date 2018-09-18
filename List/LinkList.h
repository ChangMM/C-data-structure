//
//  LinkList.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/18.
//  Copyright © 2018年 bingyan. All rights reserved.
//  单链表的模板函数
//

#ifndef LinkList_h
#define LinkList_h
#include <iostream>
#include "ListADT.h"
using namespace std;

template <class T> class Link {
public:
    T data; // 用于保存结点元素的内容
    Link<T> * next; // 指向后继结点的指针
    Link(T info, Link<T>* nextValue = NULL) {
        data = info;
        next = nextValue;
    }
    Link(Link<T>* nextValue) {
        next = nextValue;
    }
};

template <class T> class LinkList: public List<T> {
private:
    Link<T> * head, *tail; // 单链表的头、尾指针
    Link<T> *setPos(const int p); // 第p个元素指针
public:
    LinkList(); // 构造函数
    ~LinkList(); // 析构函数
    bool isEmpty(); // 判断链表是否为空
    void clear(); // 将链表存储的内容清除，成为空表
    int length(); // 返回此顺序表的当前实际长度
    bool appendElement(const T value); // 表尾添加一个元素 value，表长度增 1
    bool insertElement(const int p, const T value); // 位置 p 上插入一个元素
    bool deleteElement(const int p); // 删除位置 p 上的元素，表的长度减 1
    bool getValue(const int p, T& value);   // 返回位置 p 的元素值
    bool getPos(int &p, const T value); // 查找值为 value 的元素
};

template <class T> LinkList<T>::LinkList() {
    head = new Link<T>(0, NULL);  // 带头结点的单链表头结点head是不为空的
    tail = head; // 链表为空时头结点跟尾节点指向同一个节点
}

template <class T> LinkList<T>::~LinkList() {
    Link<T>* temp;
    Link<T>* cur = head->next;
    head->next = NULL;
    while(cur != NULL) {
        temp = cur->next;
        delete cur;
        cur = temp;
    }
    delete head;
}

template <class T> Link<T>* LinkList<T>::setPos(const int i) {
    int count = 0;

    if(i<-1){
        cout<<"list index out of range"<<endl;
        return NULL;
    } else if(i==-1) { // 将 i=-1 定位到头结点
        return head;
    }

    Link<T>* p = head->next;

    while(p != NULL && count<i) {
        p = p->next;
        count++;
    }
    if (count==i) { // 判断要获取索引的节点是否超过链表的长度
        return p;
    } else {
        cout<<"list index out of range"<<endl;
        return NULL;
    }
}

template <class T> bool LinkList<T>::insertElement(const int i, const T value) {
    Link<T> *p, *q;
    if ((p=setPos(i-1))==NULL){ //p是位置i结点的前驱
        cout<<"Insertion point is illegal"<<endl;
        return false;
    }
    q = new Link<T>(value, p->next);
    p->next = q;
    if (p==tail){ //插入点在链尾，插入结点成为新的链尾
        tail = q;
    }
    return true;
}

template <class T> bool LinkList<T>::deleteElement(const int i) {
    Link<T> *p, *q;
    p=setPos(i-1); // p 为要删除元素的前驱节点
    if (p==NULL || p==tail) {  //删除的结点不存在
        cout << "deletion is illegal" << endl;
        return false;
    }
    q = p->next; // q 为准备删除的节点
    if(q==tail){
        tail = p;
        p->next = NULL;
    } else {
        p->next = q->next;
    }
    delete q;
    return true;
}

template <class T> bool LinkList<T>::isEmpty() {
    return head->next == NULL;
}

template <class T> void LinkList<T>::clear() {
    Link<T>* cur = head->next;
    if(cur == NULL){
        return;
    }
    head->next = NULL;
    Link<T>* temp;
    while(cur != NULL) {
        temp = cur->next;
        delete cur;
        cur = temp;
    }
    tail = head;
}

template <class T> int LinkList<T>::length() {
    int count = 0;
    Link<T>* cur = head->next;
    while(cur) {
        count++;
        cur = cur->next;
    }
    return count;
}

template <class T> bool LinkList<T>::appendElement(const T value) {
    Link<T>* newLink = new Link<T>(value);
    tail->next = newLink;
    tail=newLink;
    return true;
}

template <class T> bool LinkList<T>::getPos(int& i, const T value) {
    int count = 0;
    Link<T>* cur = head->next;
    while(cur!=NULL&&cur->data!=value){
        cur = cur->next;
        count++;
    }
    if(cur==NULL){
        cout<<"can not find element: "<<value<<endl;
        return false;
    } else {
        cout<<"find element: "<<value<<" at index "<<count<< endl;
        i = count;
        return true;
    }
}

template <class T> bool LinkList<T>::getValue(const int i, T& value) {
    int count = 0;
    Link<T>* cur = head->next;
    while(cur != NULL && count<i) {
        cur=cur->next;
        count++;
    }
    if (cur==NULL) {
        cout<<i<<" is out of range"<<endl;
        return false;
    }else {
        value = cur->data;
        cout << "find element: " <<value<< endl;
        return true;
    }
}
#endif /* LinkList_h */
