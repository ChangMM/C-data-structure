//
//  ListADT.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/18.
//  Copyright © 2018年 bingyan. All rights reserved.
//  顺序表的抽象数据结构
//

#ifndef ListADT_h
#define ListADT_h

template <class T> class List {
public:
    void clear(); // 置空线性表
    bool isEmpty(); // 线性表为空时，返回 true
    bool appendElement(const T value); // 在表尾添加一个元素 value，表的长度增 1
    bool insertElement(const int p, const T value); // 在位置 p 上插入一个元素 value，表的长度增 1
    bool deleteElement(const int p); // 删除位置 p 上的元素，表的长度减 1
    bool getPos(int& p, const T value); // 查找值为 value 的元素并返回其位置 位置的值赋值给P
    bool getValue(const int p, T& value); // 把位置 p 元素值返回到变量 value
    bool setValue(const int p, const T value);
};

#endif /* ListADT_h */
