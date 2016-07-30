/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: C++
@Datetime: 16-07-25 21:40
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x == 0) return 0;
        if (x < 0) return 0x80000000; // sqrt is undefined for negative number
        
        int position = 32;
        unsigned int flag = 0x80000000;
        while (flag > 0 && !(x & flag)) {
            flag >>= 1;
            --position;
        }
        
        int half = (position - 1) / 2;
        int lowerBound = 1 << half;
        int upperBound = 1 << (half + 1);
        
        while (lowerBound < upperBound - 1) {
            int middle = (lowerBound + upperBound) / 2;
            int value = middle * middle;
            if (value == x) {
                return value;
            }
            else if (value > x || value < 0) { // handle overflow
                upperBound = middle;
            }
            else {
                lowerBound = middle;
            }
        }
        
        //if (upperBound * upperBound == x) return upperBound;
        return lowerBound;
    }
};