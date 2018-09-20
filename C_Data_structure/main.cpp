//
//  main.cpp
//  C_Data_structure
//
//  Created by cmm on 2018/9/18.
//  Copyright © 2018年 bingyan. All rights reserved.
//

#include <iostream>
using namespace std;

class Sample{
private:
    int x;
public:
    Sample(int i){
        x = i;
        cout<<"x="<<x<<" constructor called"<<endl;
    }
    ~Sample(){
        cout<<"x="<<x<<" destructor called"<<endl;
    }
};

Sample s1(1);
void func(){
    cout<<"func start"<<endl;
    static Sample s2(2);
    Sample s3(3);
    cout<<"func end"<<endl;
}
int main(){
    cout<<"main start"<<endl;
    Sample s4(4);
    s4 = 6;
    {
    Sample s5(5);
    }
    func();
    cout<<"main end"<<endl;
    return 0;
}
