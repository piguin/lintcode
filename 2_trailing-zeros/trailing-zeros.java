/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: Java
@Datetime: 16-07-23 03:06
*/

class Solution {
    /*
     * param n: As desciption
     * return: An integer, denote the number of trailing zeros in n!
     */
    public long trailingZeros(long n) {
        // write your code here
        // n! = 1 * 2 * ... * n
        if (n < 5) {
            return 0;
        }
        
        return n / 5 + trailingZeros(n / 5);
    }
};
