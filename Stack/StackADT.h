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
    // Capacity
    virtual bool empty() = 0;            // 若栈已空返回真
    virtual unsigned int size() = 0;     // 返回栈中元素的个数

    // Access value
    virtual T& top() = 0;                // 返回栈顶但不弹出，成功返回真，否则假

    // Modifiers
    virtual void pop() = 0;              // 返回栈顶内容并弹出，成功返回真，否则假
    virtual bool push(const T item) = 0; // item入栈，成功返回真，否则假
    void emplace() {};                   // 暂时不实现
    void swap(){};                       // 暂时不实现
};

#endif /* StackADT_h */
