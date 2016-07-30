/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/move-zeroes
@Language: C++
@Datetime: 16-07-23 16:11
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        int q = 0;
        int n = 0;
        for (int p = 0; p < nums.size(); ++p) {
            if (nums[p] == 0) {
                n++;
                continue;
            }
            
            if (p != q) {
                nums[q] = nums[p];
            }
            q++;
        }
        
        for (int r = nums.size() - 1; n > 0; --n, --r) {
            nums[r] = 0;
        }
    }
};