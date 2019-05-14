//
//  BigNumbers.hpp
//  MathFuncsLibs
//
//  Created by Ronald Tran on 5/13/19.
//  Copyright © 2019 Ronald Tran. All rights reserved.
//

#ifndef BigNumbers_hpp
#define BigNumbers_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <functional> //for std::

namespace BigNumbersNamespace {
    class BigNumbers {
        std::string number;
        std::vector <int> vector1;
        std::vector <int> vector2;
        std::vector <int> vector3;
        BigNumbers();
        BigNumbers(std::string);
        BigNumbers operator +(const BigNumbers &);
        BigNumbers operator -(const BigNumbers &);
        BigNumbers operator *(const BigNumbers &);
        BigNumbers operator /(const BigNumbers &);
        BigNumbers operator %(const BigNumbers &);

    };

}



#endif /* BigNumbers_hpp */
