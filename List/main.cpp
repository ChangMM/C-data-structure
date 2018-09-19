//
//  main.cpp
//  List
//
//  Created by cmm on 2018/9/18.
//  Copyright © 2018年 bingyan. All rights reserved.
//
//  带有头结点的单链表实现线性表
//

#include <iostream>
#include "LinkList.h"
using namespace std;

LinkList<int> testLinkList;



int main(int argc, const char * argv[]) {
    int temp;
    testLinkList.appendElement(5);
    testLinkList.appendElement(6);
    testLinkList.appendElement(7);

    testLinkList.getValue(2, temp);
    testLinkList.getPos(temp, 10);
    testLinkList.deleteElement(0);
    testLinkList.getValue(2, temp);
    testLinkList.getPos(temp, 7);
    testLinkList.clear();
    testLinkList.getPos(temp, 7);
    testLinkList.getValue(2, temp);
    return 0;
}
