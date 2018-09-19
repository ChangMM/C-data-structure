//
//  ArrStack.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/20.
//  Copyright © 2018年 bingyan. All rights reserved.
//  栈的顺序存储
//  栈中最多可存放的元素个数
//  栈顶位置，应小于mSize
//  存放栈元素的数组
//  栈的运算的顺序实现
//  创建一个给定长度的顺序栈实例
//

#ifndef ArrStack_h
#define ArrStack_h
#include <iostream>
#include "StackADT.h"
using namespace std;

template <class T> class ArrStack:public MyStack <T> {
private:
    int mSize;
    int index;
    T *st;
public:
    ArrStack(int size = 10) {
        mSize = size;
        index = -1;
        st = new T[mSize];
    }
    ~ArrStack() {
        delete [] st;
    }
    void clear();
    bool push(const T item);
    void pop();
    T& top();
    bool isEmpty();
    bool isFull();
};

template <class T> bool ArrStack<T>::push(const T item){
    if(isFull()){
        cout<<"The stack is overflow."<<endl;
        return false;
    } else {
        st[++index] = item;
        return true;
    }
}

template <class T> T& ArrStack<T>::top(){
    return st[index];
}

template <class T> void ArrStack<T>::pop(){
    if(index == -1) {
        cout<<"The stack is already empty"<<endl;
    } else {
        index--;
    }
}

template <class T> bool ArrStack<T>::isFull(){
    return index == (mSize - 1);
}

template <class T> bool ArrStack<T>::isEmpty(){
    return index == -1;
}

template <class T> void ArrStack<T>::clear(){
    index = -1;
}

#endif /* ArrStack_h */
