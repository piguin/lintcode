/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 16-07-25 23:44
*/

class Solution {
public:
    int swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int position = 0;
        for (auto n : nums) {
            if (n % 2 == 1) ++position;
        }
        
        int p = 0;
        int q = nums.size() - 1;
        while (p != position) {
            while (p != position && nums[p] % 2 == 1) ++p;
            while (q != position - 1 && nums[q] % 2 == 0) --q;
            if (p != position and q != position -1) {
                swap(nums[p], nums[q]);
            }
        }
    }
};