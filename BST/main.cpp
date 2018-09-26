//
//  main.cpp
//  BST
//
//  Created by cmm on 2018/9/26.
//  Copyright © 2018年 bingyan. All rights reserved.
//

#include <iostream>
#include "bst.h"
int a[8] = {12,5,18,2,9,15,19,17};

int main(int argc, const char * argv[]) {
    int len = (int) (sizeof(a) / sizeof(a[0]));
    BST<int> bstTree;
    bstTree.create(a, len);
    bstTree.travere();
    cout<<endl;
    
    bstTree.insert(13);
    bstTree.travere();
    cout<<endl;

    int b = 15;
    bstTree.cancel(bstTree.search(b));
    bstTree.travere();
    cout<<endl;

    cout<<bstTree.min(bstTree.root())->value<<" "<<bstTree.max(bstTree.root())->value<<endl;

    return 0;
}
