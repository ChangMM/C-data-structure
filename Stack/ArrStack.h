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
    int capacity = 10;            // 栈当前的容量
    T *st;
public:
    ArrStack() {
        index = -1;
        st = new T[capacity];     // 初始化的时候 新建一个长度为 10 的数组
    }
    ~ArrStack() {
        delete [] st;
    }

    bool empty();
    unsigned int size();
    T& top();
    bool push(const T item);
    void pop();
};

template <class T> bool ArrStack<T>::push(const T item){
    if(index == capacity-1){
        cout<<"The stack is expanding capacity."<<endl;
        capacity = capacity*2;
        T* buffer = new T[capacity];
        memcpy(buffer, st, sizeof(T));
        delete[] st;
        st = buffer;
    }

    if (st == nullptr){  //内存分配失败
        cout << "malloc failed." << endl;
        exit(0);
    }

    st[++index] = item;
    return true;
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

template <class T> bool ArrStack<T>::empty(){
    return index == -1;
}

template <class T> unsigned int ArrStack<T>::size(){
    return mSize;
}

#endif /* ArrStack_h */
