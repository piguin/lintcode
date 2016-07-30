/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 16-07-27 08:27
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        int len = nums.size();
        vector<long long> left(len, 1);
        vector<long long> right(len, 1);
        
        // left: 1, A[0], A[0] * A[1], ..., A[0] * ... * A[n - 2]
        for (int i = 0; i < len - 1; ++i) {
            left[i + 1] = left[i] * nums[i];
        }
        
        // right A[1] * ... * A[n - 1], A[2] * ... * A[n - 1], ..., A[n - 1]
        for (int i = len - 1; i > 0; --i) {
            right[i - 1] = right[i] * nums[i];
        }
        
        for (int i = 0; i < len; ++i) {
            left[i] *= right[i];
        }
        
        return left;
    }
};