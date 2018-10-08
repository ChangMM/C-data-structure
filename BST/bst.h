//
//  bst.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/26.
//  Copyright © 2018年 bingyan. All rights reserved.
//  二叉树的头文件
//  默认查找二叉树中没有value值相同的两个树节点
//

#ifndef bst_h
#define bst_h
#include <stack>
#include <queue>
#include <iostream>
#include "bstNode.h"
using namespace std;

template <class T> class BST{
private:
    bstNode<T>* _root;
    void _travere(bstNode<T> *_root);
    bstNode<T> * _insert(const T& data, bstNode<T>* node);
    bstNode<T>* _min(bstNode<T>* node);
    bstNode<T>* _max(bstNode<T>* node);
    bstNode<T>* _search(bstNode<T>* node, const T& data);
    void _transplant(bstNode<T>* u, bstNode<T>* v);
public:
    BST(bstNode<T>* r = NULL):_root(r){};
    ~BST(){
        if(_root != NULL){
            clear();
        }
    };
    bool empty() const;

    bstNode<T>* root();
    bstNode<T>* parent(bstNode<T> *current);

    void create(const T* arr, const int& size);
    void travere();
    void insert(const T& data);
    void cancel(bstNode<T>* node);
    bstNode<T>* search(const T& data);
    bstNode<T>* min(bstNode<T>* node);
    bstNode<T>* max(bstNode<T>* node);
    bstNode<T>* prev(bstNode<T>* node);
    bstNode<T>* next(bstNode<T>* node);
    void clear();
};

template <class T> bool BST<T>::empty() const{
    return _root == NULL;
}

template <class T> bstNode<T>* BST<T>::root(){
    return _root;
}

template <class T> bstNode<T>* BST<T>::parent(bstNode<T> *current){
    if(current == NULL || _root == current) {
        return NULL;
    }
    stack<bstNode<T>*> nodeStack;
    bstNode<T> *pointer = _root;
    nodeStack.push(NULL); // 栈底监视哨或者也可以利用 nodeStack.empty() 判断
    while(pointer){
        if(current==pointer->left || current==pointer->right){
            return pointer;
        }
        if(pointer->left != NULL){
            nodeStack.push(pointer->left);
        }
        if(pointer->right != NULL){
            nodeStack.push(pointer->right);
        }
        pointer = nodeStack.top();
        nodeStack.pop();
    }
    return NULL;
}

template <class T> void BST<T>::create(const T* arr, const int& size){
    for(int i=0; i<size;i++){
        insert(arr[i]);
    }
}

// 递归形式的深度遍历
template <class T> void BST<T>::_travere(bstNode<T> *_root){
    if(_root != NULL){
        // cout<<_root->value<<" "; //前序遍历
        _travere(_root->left);
        cout<<_root->value<<" "; //中序遍历
        _travere(_root->right);
        //cout<<_root->value<<" "; //后序遍历
    }
}

// 递归形式的深度遍历
template <class T> void BST<T>::travere(){
    _travere(_root);
}

// 插入节点 递归+非递归
template <class T> bstNode<T>* BST<T>::_insert(const T& data, bstNode<T>* node){
    if(node == NULL) {
        node = new bstNode<T>(data);
        return node;
    }
    if(node->value>data){
        node->right = _insert(data, node->right);
    } else if(node->value<data){
        node->left = _insert(data, node->left);
    } else {
        cout<<"the data have already been in the tree"<<endl;
    }
    return node;
}

template <class T> void BST<T>::insert(const T& data){
    if(_root == NULL){
        _root = new bstNode<T>(data);
        return;
    }
    bstNode<T>* node;
    bstNode<T>* tmp = _root;
    while(tmp != NULL){
        node = tmp;
        if(data < tmp->value){
            tmp = tmp->left;
        }else if(data > tmp->value){
            tmp = tmp->right;
        }else{
            cout<<"the data have already been in the tree"<<endl;
            return;
        }
    }
    if(data<node->value){
        node->left = new bstNode<T>(data);
    } else {
        node->right = new bstNode<T>(data);
    }
    return;
}

// 查找最小值 递归+非递归
template <class T> bstNode<T>* BST<T>::_min(bstNode<T>* node){
    if(node == NULL){
        return node;
    } else if(node->left == NULL){
        return node;
    }
    return _min(node->left);
}

template <class T> bstNode<T>* BST<T>::min(bstNode<T>* node){
    if(node == NULL){
        return node;
    }
    bstNode<T>* tmp = node;
    while(tmp->left != NULL){
        tmp = tmp->left;
    }
    return tmp;
}

// 查找最大值 递归+非递归
template <class T> bstNode<T>* BST<T>::_max(bstNode<T>* node){
    if(node == NULL){
        return node;
    } else if(node->right == NULL){
        return node;
    }
    return _max(node->right);
}

template <class T> bstNode<T>* BST<T>::max(bstNode<T>* node){
    if(node == NULL){
        return node;
    }
    bstNode<T>* tmp = node;
    while(tmp->right != NULL){
        tmp = tmp->right;
    }
    return tmp;
}

// 查找值 递归+非递归
template <class T> bstNode<T>* BST<T>::_search(bstNode<T>* node, const T &data){
    if(node == NULL || node->value == data){
        return node;
    }
    if(data<node->value){
        return _search(node->left, data);
    } else {
        return _search(node->right, data);
    }
}

template <class T> bstNode<T>* BST<T>::search(const T &data){
    if(_root == NULL){
        return NULL;
    }
    bstNode<T>* tmp = _root;
    while (tmp!=NULL && data!=tmp->value) {
        if(data<tmp->value)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return tmp;
}

// 后驱节点 这个需要好好看下
template <class T> bstNode<T>* BST<T>::next(bstNode<T>* node){
    if(node==NULL)
        return NULL;
    if(node->right != NULL){
        return min(node->right);
    }
    bstNode<T>* tmp = parent(node);
    while (tmp!=NULL && node==tmp->right) {
        node = tmp;
        tmp = parent(tmp);
    }
    return tmp;
}

// 前驱节点 这个需要好好看下
template <class T> bstNode<T>* BST<T>::prev(bstNode<T>* node){
    if(node == NULL)
        return NULL;
    if(node->left != NULL){
        return max(node->left);
    }
    bstNode<T>* tmp = parent(node);
    while (tmp!=NULL && node==tmp->left) {
        node = tmp;
        tmp = parent(tmp);
    }
    return tmp;
}

template <class T> void BST<T>::_transplant(bstNode<T>* u, bstNode<T>* v){
    if(u == _root) {
        _root = v;
    } else if(parent(u)->left == u){
        parent(u)->left = v;
    } else {
        parent(u)->right = v;
    }
}

// 这个过程比较复杂，需要多看下
template <class T> void BST<T>::cancel(bstNode<T>* node){
    if(node->left == NULL){
        _transplant(node, node->right);
    } else if(node->right == NULL){
        _transplant(node, node->left);
    } else {
        bstNode<T>* tmp = min(node->right);
        if(parent(tmp) != node){
            _transplant(tmp, tmp->right);
            tmp->right = node->right;
        }
        _transplant(node, tmp);
        tmp->left = node->left;
    }
    delete node;
}

template <class T> void _clear(bstNode<T>* _root){
    if(_root!=NULL){
        _clear(_root->left);
        _clear(_root->right);
        delete _root;
        _root->right = NULL;
        _root->left = NULL;
        _root=NULL;
    }
}

template <class T> void BST<T>::clear(){
    _clear(_root);
    _root = NULL;
}

#endif /* bst_h */
