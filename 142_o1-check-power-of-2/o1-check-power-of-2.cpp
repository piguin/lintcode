/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/o1-check-power-of-2
@Language: C++
@Datetime: 16-07-25 04:57
*/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        return n > 0 && (~(n ^ (n - 1)) & n) == 0;
    }
};