//
//  MyStack.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/20.
//  Copyright © 2018年 bingyan. All rights reserved.
//

#ifndef MyStack_h
#define MyStack_h

template <class T> class MyStack {
public: // 栈的运算集
    void clear(); // 变为空栈
    bool push(const T item); // item入栈，成功返回真，否则假
    bool pop(T& item); // 返回栈顶内容并弹出，成功返回真，否则假
    bool top(T& item); // 返回栈顶但不弹出，成功返回真，否则假
    bool isEmpty(); // 若栈已空返回真
    bool isFull(); // 若栈已满返回真
};


#endif /* MyStack_h */
