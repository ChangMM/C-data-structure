//
//  main.cpp
//  KMP
//
//  Created by cmm on 2018/9/21.
//  Copyright © 2018年 bingyan. All rights reserved.
//
//

#include <iostream>
#include <cstring>
using namespace std;

void findNext(char* p, int* next){
    next[0] = 0;
    int i = 1, j = 0;
    while(i<strlen(p)){
        if(p[i] == p[j]){
            j++;
        } else {
            j = 0;
        }
        next[i] = j;
        i++;
    }
}

int KMP(char* t, char* p, int* next){
    int i = 0;
    int j = 0;

    if(strlen(p) > strlen(t)){
        return -1;
    }

    while (i < strlen(t) && j < strlen(p)){
        if(t[i] == p[j]){
            i++;
            j++;
        } else {
            if(j == 0) {
                i++;
            } else {
                j = next[j-1];
            }
        }
    }

    if (j == strlen(p))
        return i - j;
    else
        return -1;
}

int main(int argc, const char * argv[]) {
    int next[20] = {0};
    char t[] = "BBC ABCDAB ABCDABCDABDE";
    char p[] = "ABCD";
    findNext(p, next);
    cout<<"result:"<<KMP(t, p, next)<<endl;
    return 0;
}
