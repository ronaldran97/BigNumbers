//
//  BigNumbers.cpp
//  MathFuncsLibs
//
//  Created by Ronald Tran on 5/13/19.
//  Copyright © 2019 Ronald Tran. All rights reserved.
//

#include "BigNumbers.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

namespace BigNumbersNamespace {
    /*!
     * \brief default contructor
     * \details Initializes BigNumber to value of zero
     */
    BigNumbers::BigNumbers(){}
    
    /*!
     * \brief contructor
     * \details converts strings to ints
     * \param string is the parameter and it is a string
     */
    BigNumbers::BigNumbers(std::string string) {
        number = string;
        for (auto conv : number) {
            vector1.push_back(conv - '0');
        }
        std::cout << number << std::endl;
    }
    
    /*!
     * \brief vectors to ints
     * \details changes integers in the vectors to integers
     * \param vector vector
     */
    int vectorToInt(std::vector<int> vector) {
        std::reverse(vector.begin(), vector.end());
        int dec = 1;
        int total = 0;
        for (auto& it : vector) {
            total += it * dec;
            dec *= 10;
        }
        return total;
    }

    /*!
     * \brief Operation overloading for + addiditon functionality
     * \param myBigNum takes in reference to myBigNum
     */
    BigNumbers BigNumbers::operator +(const BigNumbers & myBigNum) {
        BigNumbers result;
        int carry = 0;
        for (auto c : myBigNum.number) {
            vector2.push_back(c - '0');
        }
        while(vector2.size() < vector1.size()) {
            vector2.insert(vector2.begin() + 0, 0);
        }
        while (vector1.size() < vector2.size()) {
            vector1.insert(vector1.begin() + 0, 0);
        }
        
        for (long i = vector1.size(); i != 0; i--) {
            int num = (vector1[i - 1] + vector2[i - 1] + carry) % 10;
            vector3.push_back(num);
            if (vector1[i - 1] + vector2[i - 1] + carry >= 10) {
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        if (carry == 1) {
            vector3.push_back(1);
        }
        
        
        std::reverse(vector3.begin(), vector3.end());
        std::ostringstream resultInt;
        if (!vector3.empty()) {
            std::copy(vector3.begin(), vector3.end() - 1, std::ostream_iterator<int>(resultInt, ""));
            resultInt << vector3.back();
        }
        
        result = resultInt.str();
        
        vector2.clear();
        vector3.clear();
        
        return result;
    }

    
    /*!
     * \brief Operation overloading for * Multiplication functionality
     * \param myBigNum Takes in BigNumberClass
     */
    BigNumbers BigNumbers::operator * (const BigNumbers & myBigNum) {
        
        BigNumbers result;
        BigNumbers prod1;
        BigNumbers prod2;
        std::vector<int> products;
        for (auto c : myBigNum.number) {
            vector2.push_back(c - '0');
        }
        int res = vectorToInt(vector1) * vectorToInt(vector2);
        std::ostringstream oss;
        oss << res;
        result = oss.str();
        vector2.clear();
        return result;
    }

    /*!
     * \brief Operation overloading for / division functionality
     * \param myBigNum Takes in BigNumberClass
     */
    BigNumbers BigNumbers::operator / (const BigNumbers & myBigNum) {
        BigNumbers result;
        for (auto c : myBigNum.number) {
            vector2.push_back(c - '0');
        }
        int res = vectorToInt(vector1) / vectorToInt(vector2);
        std::ostringstream oss;
        oss << res;
        result = oss.str();
        vector2.clear();
        return result;
        
    }

    /*!
     * \brief Operation overloading for % Modulus functionality
     * \param myBigNum Takes in BigNumberClass
     */
    BigNumbers BigNumbers::operator % (const BigNumbers & myBigNum) {
        BigNumbers result;
        for (auto c : myBigNum.number) {
            vector2.push_back(c - '0');
        }
        int res = vectorToInt(vector1) % vectorToInt(vector2);
        std::ostringstream oss;
        oss << res;
        result = oss.str();
        vector2.clear();
        return result;
    }
    
    /*!
     * \brief Operation overloading for - subtraction functionality
     * \param myBigNum Takes in BigNumberClass
     */
    BigNumbers BigNumbers::operator - (const BigNumbers & myBigNum) {
        BigNumbers result;
        std::vector<int> temp;
        
        std::ostringstream resultInt; //holds string of resulting int
        int carry = 0;
        for (auto c : myBigNum.number) {
            vector2.push_back(c - '0');
        }
        
        while (vector2.size() < vector1.size()) {
            vector2.insert(vector2.begin() + 0, 0);
        }
        
        while (vector1.size() < vector2.size()) {
            vector1.insert(vector1.begin() + 0, 0);
        }
        
        for (int i = 0; i < vector1.size(); i++) {
            temp.push_back(vector1[i]);
        }
        
        //checks for negative
        int neg = vectorToInt(temp) - vectorToInt(vector2);
        
        //checks for negative
        if (neg < 0) {
            for (long i = temp.size(); i != 0; i--) {
                int num = ((vector2[i - 1] + carry) - temp[i - 1]);
                if (num < 0) {
                    carry = 10;
                    num = ((vector2[i - 1] + carry) - temp[i - 1]);
                    vector3.push_back(num);
                    carry = 0;
                    long j = i - 2;
                    vector2[j] = vector2[j] - 1;
                    j--;
                }
                else {
                    vector3.push_back(num);
                }
            }
            resultInt << "-"; //negtive sign
        }
        else {
            
            for (long i = temp.size(); i != 0; i--) {
                int num = ((temp[i - 1] + carry) - vector2[i - 1]);
                if (num < 0) {
                    carry = 10;
                    num = ((temp[i - 1] + carry) - vector2[i - 1]);
                    vector3.push_back(num);
                    carry = 0;
                    long j = i - 2;
                    temp[j] = temp[j] - 1;
                    j--;
                }
                else {
                    vector3.push_back(num);
                }
            }
        }
        
        while (vector3.back() == 0) {
            vector3.pop_back();
        }
        
        std::reverse(vector3.begin(), vector3.end());
        
        if (!vector3.empty()) {
            std::copy(vector3.begin(), vector3.end() - 1, std::ostream_iterator<int>(resultInt, ""));
            resultInt << vector3.back();
        }
        result = resultInt.str();
        vector2.clear();
        vector3.clear();
        return result;
    }

}
