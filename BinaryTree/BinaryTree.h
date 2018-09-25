//
//  BinaryTree.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/23.
//  Copyright © 2018年 bingyan. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include <stack>
#include <queue>
#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

template <class T> class BinaryTree{
private:
    BinaryTreeNode<T>* root;
public:
    BinaryTree(BinaryTreeNode<T>* _root = NULL):root(_root){}; //构造函数
    ~BinaryTree() {
        if(root!=NULL){
            _clear(root);
        }
    };
    bool isEmpty() const; // 判定二叉树是否为空树

    BinaryTreeNode<T>* getRoot(); // 返回根结点
    BinaryTreeNode<T>* getParent(BinaryTreeNode<T> *current);

    // 几种遍历算法
    void preOrder();   // 前序遍历二叉树或其子树  非递归形式
    void inOrder();    // 中序遍历二叉树或其子树  非递归形式
    void postOrder();  // 后序遍历二叉树或其子树  非递归形式
    void levelOrder(); // 广度遍历二叉树或其子树  非递归形式
    void depthOrder(BinaryTreeNode<T> *root); // 深度遍历二叉树或其子树 递归形式

    // 树的节点操作
    void createTree(const T* arr, int& index, int& size, const T& invalid); // 构造新树
    void deleteNode(BinaryTreeNode<T> *node); // 删除节点
    void insertNode(BinaryTreeNode<T> *node); // 插入节点
    void clear(); // 删除二叉树或子树
    void clear(BinaryTreeNode<T> *node); // 删除二叉树或子树
};

template <class T> bool BinaryTree<T>::isEmpty() const{
    return root == NULL;
}

template <class T> BinaryTreeNode<T>* BinaryTree<T>::getRoot(){
    return root;
}

template <class T> BinaryTreeNode<T>* BinaryTree<T>::getParent(BinaryTreeNode<T> *current){
    stack<BinaryTreeNode<T>*> nodeStack;
    BinaryTreeNode<T> *pointer = root;
    nodeStack.push(NULL); // 栈底监视哨或者也可以利用 nodeStack.empty() 判断
    while(pointer){
        if(current==pointer->getLeft() || current==pointer->getRight()){
            return pointer;
        }
        if(pointer->getLeft() != NULL){
            nodeStack.push(pointer->getLeft());
        }
        if(pointer->getRight() != NULL){
            nodeStack.push(pointer->getRight());
        }
        pointer = nodeStack.top();
        nodeStack.pop();
    }
    return NULL;
}

// 递归形式的深度遍历
template <class T> void BinaryTree<T>::depthOrder(BinaryTreeNode<T> *node){
    if(root != NULL){
        //cout<<root->getValue()<<" "; //前序遍历
        depthOrder(root->getLeft());
        cout<<root->getValue()<<" "; //中序遍历
        depthOrder(root->getRight());
        //cout<<root->getValue()<<" "; //后序遍历
    }
}

// 非递归形式的前序遍历
template <class T> void BinaryTree<T>::preOrder(){
    stack<BinaryTreeNode<T>*> aStack;
    BinaryTreeNode<T>* pointer = root;
    aStack.push(NULL);
    while(pointer){
        cout<<pointer->getValue()<<" ";
        if (pointer->getRight() != NULL){
            aStack.push(pointer->getRight());
        }

        if (pointer->getLeft() != NULL){
            pointer = pointer->getLeft();
        } else{
            pointer = aStack.top();
            aStack.pop();
        }
    }
}

// 非递归形式的中序遍历
template <class T> void BinaryTree<T>::inOrder(){
    stack<BinaryTreeNode<T>*> aStack;
    BinaryTreeNode<T>* pointer = root;
    while(!aStack.empty() || pointer){
        while(pointer){
            aStack.push(pointer);
            pointer = pointer->getLeft();
        }
        if(!aStack.empty()){
            pointer = aStack.top();
            aStack.pop();
            cout<<pointer->getValue()<<" ";
            pointer = pointer->getRight();
        }
    }
}

// 非递归形式的后序遍历
template <class T> void BinaryTree<T>::postOrder(){
    stack<BinaryTreeNode<T>*> aStack;
    BinaryTreeNode<T>* pointer = root, *r = NULL; // pointer 表示当前访问节点 r表示最近访问节点
    while(!aStack.empty() || pointer){
        while(pointer){
            aStack.push(pointer);
            pointer = pointer->getLeft();
        }
        if(!aStack.empty()){
            pointer = aStack.top();
            if (pointer->getRight() && pointer->getRight() != r){  // 如果右子树存在，且未访问过
                pointer = pointer->getRight();
                aStack.push(pointer);
                pointer = pointer->getLeft();
            }else{
                aStack.pop();
                cout<<pointer->getValue()<<" ";
                r = pointer;
                pointer = NULL;
            }
        }
    }
}

// 非递归形式的广度遍历
template <class T> void BinaryTree<T>::levelOrder(){
    queue<BinaryTreeNode<T>*> aQueue;
    BinaryTreeNode<T>* pointer = root;
    if (pointer)
        aQueue.push(pointer);
    while(!aQueue.empty()){
        pointer = aQueue.front();
        aQueue.pop();
        cout<<pointer->getValue()<<" ";
        if(pointer->getLeft())
            aQueue.push(pointer->getLeft()); // 左子树进队列

        if(pointer->getRight())
            aQueue.push(pointer->getRight());// 右子树进队列
    }
}

template <class T> BinaryTreeNode<T>* _create(const T* arr, int& index, const int& size, const T& invalid){
    BinaryTreeNode<T>* root = NULL;
    if(index < size && arr[index] != invalid){
        root = new BinaryTreeNode<T>(arr[index]);
        root->setLeft(_create(arr, ++index, size, invalid));
        root->setRight(_create(arr, ++index, size, invalid));
    }
    return root;
}

template <class T> void BinaryTree<T>::createTree(const T* arr, int& index, int& size, const T& invalid){
    root = _create(arr, index, size, invalid);
}

template <class T> void _clear(BinaryTreeNode<T>* _root){
    if(_root!=NULL){
        _clear(_root->getLeft());
        _clear(_root->getRight());
        delete _root;
        _root->setRight(NULL);
        _root->setLeft(NULL);
        _root=NULL;
    }
}

template <class T> void BinaryTree<T>::clear(){
    _clear(root);
    root = NULL;
}
#endif /* BinaryTree_h */
