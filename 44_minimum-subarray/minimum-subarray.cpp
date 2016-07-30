/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/minimum-subarray
@Language: C++
@Datetime: 16-07-27 06:30
*/

class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }
    
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        int sumSofar = nums[0];
        int minSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            sumSofar = min(n, sumSofar + n);
            minSum = min(minSum, sumSofar);
        }
        return minSum;
    }
};
