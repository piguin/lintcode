/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/ugly-number
@Language: C++
@Datetime: 16-07-25 21:50
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        if (num <= 0) return false;
        
        while (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
            if (num % 2 == 0) num /= 2;
            if (num % 3 == 0) num /= 3;
            if (num % 5 == 0) num /= 5;
        }
        
        return num == 1;
    }
};