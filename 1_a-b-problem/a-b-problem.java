/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/a-b-problem
@Language: Java
@Datetime: 16-07-23 01:59
*/

class Solution {
    /*
     * param a: The first integer
     * param b: The second integer
     * return: The sum of a and b
     */
    public int aplusb(int a, int b) {
        if (b == 0) {
            return a;
        }
        return aplusb(a ^ b, (a & b) << 1);
    }
};