/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/single-number
@Language: C++
@Datetime: 16-07-24 22:37
*/

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        int result;
        for (int i = 0; i < A.size(); ++i) {
            result ^= A[i];
        }
        return result;
    }
};
