//
//  bstNode.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/26.
//  Copyright © 2018年 bingyan. All rights reserved.
//

#ifndef bstNode_h
#define bstNode_h
template <class T> class bstNode{
public:
    T value; // 二叉树节点的数据域
    bstNode<T>* left;  // 左子树节点
    bstNode<T>* right; // 右子树节点
    bstNode(const T& _data, bstNode* _l = NULL, bstNode* _r = NULL):value(_data), left(_l), right(_r){};
    bstNode<T>* parent(bstNode<T>* root); // 返回父节点
    bool isLeaf() const; // 判断是否为叶结点
};

template<class T> bstNode<T>* bstNode<T>::parent(bstNode<T>* root){
    bstNode<T> *temp;
    if(root == NULL){
        return NULL;
    }

    if(this == root->left || this == root->right){
        return root;
    }

    if(root->right && (temp = this->parent(root->right))){
        return temp;
    }

    if(root->left && (temp = this->parent(root->left))){
        return temp;
    }
    return NULL;
}

template <class T> bool bstNode<T>::isLeaf() const{
    return left == NULL && right == NULL;
}

#endif /* bstNode_h */
