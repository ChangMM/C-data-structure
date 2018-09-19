//
//  StackADT.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/20.
//  Copyright © 2018年 bingyan. All rights reserved.
//  栈的抽象数据模型
//

#ifndef StackADT_h
#define StackADT_h

template <class T> class MyStack {
public:
    virtual void clear() = 0; // 变为空栈
    virtual bool push(const T item) = 0; // item入栈，成功返回真，否则假
    virtual void pop() = 0; // 返回栈顶内容并弹出，成功返回真，否则假
    virtual T& top() = 0; // 返回栈顶但不弹出，成功返回真，否则假
    virtual bool isEmpty() = 0; // 若栈已空返回真
    virtual bool isFull() = 0; // 若栈已满返回真
};

#endif /* StackADT_h */
