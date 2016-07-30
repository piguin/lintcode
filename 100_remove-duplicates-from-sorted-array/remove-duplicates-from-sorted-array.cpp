/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: C++
@Datetime: 16-07-23 16:32
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        
        int q = 0;
        for (int p = 1; p < nums.size(); ++p) {
            if (nums[q] == nums[p]) continue;
            nums[++q] = nums[p];
        }
        return ++q;
    }
};