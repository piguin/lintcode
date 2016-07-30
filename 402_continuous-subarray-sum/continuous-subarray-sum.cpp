/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/continuous-subarray-sum
@Language: C++
@Datetime: 16-07-23 05:02
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        int maxSumCurr = A[0];
        int maxSumMax = A[0];
        vector<int> indices(2);
        indices[0] = 0;
        indices[1] = 0;
        int startIndex = 0;

        for (int i = 1; i < A.size(); ++i) {
            maxSumCurr += A[i];
            if (maxSumCurr < A[i]) {
                startIndex = i;
                maxSumCurr = A[i];
            }
            if (maxSumMax < maxSumCurr) {
                indices[0] = startIndex;
                indices[1] = i;
                maxSumMax = maxSumCurr;
            }
        }

        return indices;
    }
};