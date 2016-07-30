/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 16-07-25 23:58
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(unsigned int a, unsigned int b) {
        unsigned int diff = a ^ b;
        int numBits = 0;
        while (diff > 0) {
            diff &= ~(diff ^ (diff - 1));
            ++numBits;
        }
        return numBits;
    }
};