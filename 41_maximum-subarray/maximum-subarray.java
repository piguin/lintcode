/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: Java
@Datetime: 16-07-23 04:22
*/

public class Solution {
    public int max(int a, int b) {
        return (a > b) ? a : b;
    }
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    public int maxSubArray(int[] nums) {
        int max_ending_here = nums[0];
        int max_so_far = nums[0];
        for(int i = 1; i < nums.length; ++i) {
            int x = nums[i];
            max_ending_here = max(x, max_ending_here + x);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
}