//
//  main.cpp
//  TestingLib
//
//  Created by Ronald Tran on 5/9/19.
//  Copyright © 2019 Ronald Tran. All rights reserved.
//

#include <iostream>

#include "MathFuncsLib.h"
#include "BigNumbers.hpp"

using namespace std;



int main()
{
    double a = 7.4;
    int b = 99;
    
    cout << "a + b = " <<
    MathFuncs::MyMathFuncs::Add(a, b) << endl;
    cout << "a - b = " <<
    MathFuncs::MyMathFuncs::Subtract(a, b) << endl;
    cout << "a * b = " <<
    MathFuncs::MyMathFuncs::Multiply(a, b) << endl;
    cout << "a / b = " <<
    MathFuncs::MyMathFuncs::Divide(a, b) << endl;
    
    BigNumbers operator +(const BigNumbers &);
    BigNumbers operator -(const BigNumbers &);
    BigNumbers operator *(const BigNumbers &);
    BigNumbers operator /(const BigNumbers &);
    BigNumbers operator %(const BigNumbers &);
    
    
    return 0;
}
