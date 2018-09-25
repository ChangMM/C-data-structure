//
//  main.cpp
//  BinaryTree
//
//  Created by cmm on 2018/9/23.
//  Copyright © 2018年 bingyan. All rights reserved.
//
//  https://blog.csdn.net/LLZK_/article/details/52829525
//

#include <iostream>
#include "BinaryTree.h"
int a[10] = {1,2,3,-1,-1,4,-1,-1,5,6};

int main(int argc, const char * argv[]) {
    int start = 0, size = (int) (sizeof(a) / sizeof(a[0]));
    BinaryTree<int> bstTree;
    bstTree.createTree(a, start, size, -1);
    bstTree.levelOrder(); // 广度优先搜索
    cout<<endl;
    bstTree.inOrder();    // 中序遍历
    cout<<endl;
    bstTree.preOrder();   // 前序遍历
    cout<<endl;
    bstTree.postOrder();  // 后序遍历
    cout<<endl;

    cout<<bstTree.getParent(bstTree.getRoot()->getRight()->getRight())->getValue()<<endl;
    cout<<bstTree.getRoot()->getRight()->getLeft()->getParent(bstTree.getRoot())->getValue()<<endl;

    bstTree.clear();
    return 0;
}
