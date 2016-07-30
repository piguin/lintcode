/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/partition-array
@Language: C++
@Datetime: 16-07-28 03:18
*/

class Solution {
public:
    int swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    int partitionArray(vector<int> &nums, int k) {
        int p = 0;
        for (int n : nums) if (n < k) ++p;
        
        int len = nums.size();
        int i = 0;
        int j = len - 1;
        while (i != p) {
            while (i != p && nums[i] < k) ++i;
            while (j != p && nums[j] >= k) --j;
            if (i != p) {
                swap(nums[i], nums[j]);
            }
        }
        
        return p;
    }
};