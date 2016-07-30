/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/count-1-in-binary
@Language: C++
@Datetime: 16-07-24 19:20
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int origNum) {
        unsigned int num = *(unsigned int *)(&origNum);
        int c = 0;
        while (num > 0) {
            num &= ~(num ^ (num - 1));
            ++c;
        }
        return c;
    }
};