//
//  MathFuncsLib.cpp
//  MathFuncsLibs
//
//  Created by Ronald Tran on 5/9/19.
//  Copyright © 2019 Ronald Tran. All rights reserved.
//

#include <stdio.h>
#include "MathFuncsLib.h"
#include "BigNumbers.hpp"

#include <stdexcept>

using namespace std;
using namespace BigNumbersNamespace;
namespace MathFuncs
{
    double MyMathFuncs::Add(double a, double b)
    {
        return a + b;
    }
    
    double MyMathFuncs::Subtract(double a, double b)
    {
        return a - b;
    }
    
    double MyMathFuncs::Multiply(double a, double b)
    {
        return a * b;
    }
    
    double MyMathFuncs::Divide(double a, double b)
    {
        return a / b;
    }
    
//    BigNumbers::+ (BigNumbers right)

}

