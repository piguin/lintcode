/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/single-number-iii
@Language: C++
@Datetime: 16-07-25 05:35
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        vector<int> ret(2);
        int len = A.size();
        
        // first pass, get XOR of x and y
        unsigned int result = 0;
        for (int i = 0; i < len; ++i) {
            result ^= A[i];
        }
        
        // second pass, use differing bit to find
        unsigned differingBit = result ^ (result & ~(result ^ (result - 1)));
        int x = 0, y = 0;
        for (int i = 0; i < len; ++i) {
            if (A[i] & differingBit) x ^= A[i];
            else y ^= A[i];
        }
        
        ret[0] = x;
        ret[1] = y;
        return ret;
    }
};