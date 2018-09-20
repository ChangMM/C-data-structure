//
//  LinkStack.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/20.
//  Copyright © 2018年 bingyan. All rights reserved.
//  利用单链表实现栈
//

#ifndef LinkStack_h
#define LinkStack_h
#include <iostream>
#include "StackADT.h"
using namespace std;

// 链式栈的每个节点的数据
template <class T> class Node{
public:
    T data;         // 用于保存结点元素的内容
    Node<T> * next; // 指向后继结点的指针
    Node(const T _data, Node<T>* nextValue = NULL) {
        data = _data;
        next = nextValue;
    }
};

template <class T> class LinkStack:public MyStack<T>{
private:
    int mSize;         // 栈的容量
    Node<T>* head;    // 栈的头指针
public:
    LinkStack(){  //构造函数
        head = NULL;
    }
    ~LinkStack(){ //析构函数
        Node<T>* temp;
        while(head->next != NULL){
            temp = head->next;
            delete head;
            head = temp;
        }
        delete head;
        head = NULL;
    }
    bool empty();
    unsigned int size();
    T& top();
    bool push(const T item);
    void pop();
};

template <class T> bool LinkStack<T>::empty(){
    return mSize == 0;
}

template <class T> unsigned int LinkStack<T>::size(){
    return mSize;
}

template <class T> bool LinkStack<T>::push(const T item){
    Node<T>* temp = new Node<T>(item, head);
    head = temp;
    mSize++;
    return true;
}

template <class T> void LinkStack<T>::pop(){
    Node<T>* temp;
    if(mSize == 0){
        cout<<"The stack is alredy empty!"<<endl;
    }
    temp = head->next;
    delete head;
    head = temp;
    mSize--;
}

template <class T> T& LinkStack<T>::top(){
    return head->data;
}

#endif /* LinkStack_h */
