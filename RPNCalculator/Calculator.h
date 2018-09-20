//
//  Calculator.h
//  C_Data_structure
//
//  Created by cmm on 2018/9/20.
//  Copyright © 2018年 bingyan. All rights reserved.
//  利用栈实现后缀表达式求值的类、需要注意的是注意运算符两边操作数的顺序
//

#ifndef Calculator_h
#define Calculator_h
#include <iostream>
#include <stack>
using namespace std;

class Calculator{
private:
    stack<double> s; // 用于将操作数压入的栈
    bool getTwoOperands(double& opd1, double& opd2); // 从栈顶弹出两个操作数opd1和opd2
    void compute(char op); // 取两个操作数，并按照运算符对两个操作数进行计算
public:
    Calculator(void){} ; // 创建计算器实例，开辟一个空栈
    void run(void); // 读入后缀表达式，遇“=”符号结束
    void clear(void); // 清除计算器，为下一次计算做准备
};

bool Calculator::getTwoOperands(double &opd1, double &opd2){
    if(s.empty()){
        cerr<<"后缀表达式错误"<<endl;
        return false;
    }
    opd1 = s.top();
    s.pop();
    if(s.empty()){
        cerr<<"后缀表达式错误"<<endl;
        return false;
    }
    opd2 = s.top();
    s.pop();
    return true;
}

void Calculator::compute(char op){
    double opd1, opd2, result;
    if(getTwoOperands(opd1, opd2)){
        switch (op) {
            case '+':
                result = opd1 + opd2;
                break;
            case '-':
                result = opd2 - opd1;
                break;
            case '*':
                result = opd1 * opd2;
                break;
            case '/':
                if(opd2 == 0.0){
                    cerr<<"can't divide by zero."<<endl;
                    clear();
                    return;
                } else {
                    result = opd2 / opd1;
                }
                break;
        }
//        cout<<"计算结果为："<<result<<endl;
        s.push(result);
    } else {
        clear();
    }
}

void Calculator::run(){
    char c;
    double newoperand;
    while (cin >> c && c != '=') {
        switch(c) {
            case '+':
            case '-':
            case '*':
            case '/':
                compute(c);
                break;
            default:
                cin.putback(c);
                cin>>newoperand;
                cout<<"当前数据为："<<newoperand<<endl;
                s.push(newoperand);
                break;
        }
    }
    if(!s.empty() && c == '='){
        cout<< "计算结果为：" << s.top() << endl;
        s.pop();
    }
}

void Calculator::clear(){
    while (!s.empty()) {
        s.pop();
    }
}
#endif /* Calculator_h */
