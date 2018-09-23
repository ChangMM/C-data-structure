//
//  BinaryTreeNode.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/23.
//  Copyright © 2018年 bingyan. All rights reserved.
//  二叉树节点的 ADT 定义
//

#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h

template <class T> class BinaryTreeNode{
private:
    T value; // 二叉树节点的数据域
    BinaryTreeNode<T>* left;  // 左子树节点
    BinaryTreeNode<T>* right; // 右子树节点
public:
    BinaryTreeNode(const T& _data, const BinaryTreeNode* _l = NULL, const BinaryTreeNode* _r = NULL):value(_data), left(_l), right(_r){};

    T getValue() const;
    void setValue(const T& val); // 设置数据域

    BinaryTreeNode<T>* getLeft() const; // 返回左子节点
    BinaryTreeNode<T>* getRight() const; // 返回右子节点
    void setLeft(const BinaryTreeNode<T>* node); // 设置左子节点
    void setRight(const BinaryTreeNode<T>* node); // 设置右子节点

    BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* root); // 返回父节点

    bool isLeaf() const; // 判断是否为叶结点
    BinaryTreeNode<T>& operator= (const BinaryTreeNode<T>& node); // 重载赋值操作符
};

template<class T> T BinaryTreeNode<T>::getValue() const{
    return value;
}

template<class T> void BinaryTreeNode<T>::setValue(const T& val){
    value = val;
}

template<class T> BinaryTreeNode<T>* BinaryTreeNode<T>::getLeft() const{
    return left;
}

template<class T> BinaryTreeNode<T>* BinaryTreeNode<T>::getRight() const{
    return right;
}

template<class T> void BinaryTreeNode<T>::setRight(const BinaryTreeNode<T>* node){
    right = node;
}

template<class T> void BinaryTreeNode<T>::setLeft(const BinaryTreeNode<T>* node){
    left = node;
}

template<class T> BinaryTreeNode<T>* BinaryTreeNode<T>::getParent(BinaryTreeNode<T>* root){
    BinaryTreeNode<T> *temp;
    if(root == NULL){
        return NULL;
    }

    if(this == root->getLeft() || this == root->getRight()){
        return root;
    }

    if(root->getLeft() && (temp = this->getParent(root->getLeft()))){
        return temp;
    }

    if(root->getRight() && (temp = this->getParent(root->getRight()))){
        return temp;
    }
    return NULL;
}

template <class T> bool BinaryTreeNode<T>::isLeaf() const{
    return left == NULL && right == NULL;
}

#endif /* BinaryTreeNode_h */
