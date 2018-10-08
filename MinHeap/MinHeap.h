//
//  MinHeap.h
//  C_Data_structure
//
//  Created by cmm on 2018/10/9.
//  Copyright © 2018 bingyan. All rights reserved.
//  最小堆的ADT定义
//

#ifndef MinHeap_h
#define MinHeap_h
#include <math.h>

template <class T> class MinHeap {
private:
    T* heapArray;
    int CurrentSize;
    int MaxSize;
    void buildHeap(); // 构造函数,n为最大元素数目
public:
    MinHeap(int n, const T* array):MaxSize(n),heapArray(array){ // n 为堆的最大元素数目
        if(array == NULL){
            CurrentSize = 0;
        } else {
            int len = (sizeof(array) / sizeof(T));
            if(len>MaxSize) {
                CurrentSize = MaxSize;
            } else {
                CurrentSize = len;
            }
            buildHeap();
        }
    };

    virtual ~MinHeap(){ // 析构函数
        if (heapArray != NULL) {
            delete []heapArray;
        }
    };
    bool isLeaf(int pos) const;     // 如果是叶结点，返回TRUE
    int leftchild(int pos) const;   // 返回左孩子位置
    int rightchild(int pos) const;  // 返回右孩子位置
    int parent(int pos) const;      // 返回父结点位置
    bool remove(int pos);           // 删除给定下标的元素
    bool insert(const T& newNode);  // 向堆中插入新元素newNode
    T& removeMin();                 // 从堆顶删除最小值
    void siftUp(int position);
    void siftDown(int postion);
};

template<class T> int MinHeap<T>::leftchild(int pos) const{
    return 2*pos + 1;
}

template<class T> int MinHeap<T>::rightchild(int pos) const{
    return 2*pos + 2;
}

template<class T> int MinHeap<T>::parent(int pos) const{
    return int(floor((pos-1)/2));
}

template<class T> void MinHeap<T>::siftDown(int postion){
    int i = postion;
    int j = 2*postion +1;
    T temp = heapArray[i];
    while (j < CurrentSize) {
        if((j < CurrentSize-1)&&(heapArray[j] > heapArray[j+1]))
            j++; // j指向数值较小的子结点
        if (temp > heapArray[j]) {
            heapArray[i] = heapArray[j];
            i = j;
            j = 2*j + 1;
        } else {
            break;
        }
    }
    heapArray[i]=temp;
}

template<class T> void MinHeap<T>::siftUp(int position) { // 从position向上开始调整，使序列成为堆
    int temppos=position;
    T temp = heapArray[temppos];
    while((temppos>0) && (heapArray[parent(temppos)] > temp)) {
        heapArray[temppos]=heapArray[parent(temppos)];
        temppos=parent(temppos);
    }
    heapArray[temppos]=temp;// 找到最终位置
}

template<class T>void MinHeap<T>::buildHeap(){
    for (int i=CurrentSize/2-1; i>=0; i--) // 反复调用筛选函数
        siftDown(i);
}

template <class T> bool MinHeap<T>::insert(const T& newNode){
    if(CurrentSize==MaxSize) return false;
    heapArray[CurrentSize]=newNode;
    siftUp(CurrentSize); // 向上调整
    CurrentSize++;
}

template<class T> bool MinHeap<T>::remove(int pos) {
    if((pos<0)||(pos>=CurrentSize))
        return false;
    T temp = heapArray[pos];
    heapArray[pos]=heapArray[--CurrentSize];
    if (heapArray[parent(pos)]> heapArray[pos])
        siftUp(pos); //上升筛
    else
        siftDown(pos); //向下筛
    return true;
}

template<class T> T& MinHeap<T>::removeMin() {
    T temp = heapArray[0];
    remove(0);
    return temp;
}

#endif /* MinHeap_h */

