/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array-ii
@Language: C++
@Datetime: 16-07-23 16:40
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
        int r = 0;
        int c = 1;
        for (int p = 1; p < nums.size(); ++p) {
            if (nums[p] == nums[q]) {
                if (++c == 2) {
                    nums[++r] = nums[p];
                    ++q;
                }

                continue;
            }
            
            ++q;
            nums[++r] = nums[p];
            c = 1;
        }
        
        return ++r;
    }
};