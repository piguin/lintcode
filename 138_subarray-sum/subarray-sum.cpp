/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: C++
@Datetime: 16-07-28 05:19
*/

class Solution {
public:
    int abs(int a) {
        return a < 0 ? -a : a;
    }
    
    int minAbs(int a, int b) {
        return abs(a) < abs(b) ? a : b;
    }
    
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        int len = nums.size();
        for (int i = 1; i < len; ++i) nums[i] += nums[i - 1];
        
        vector<int> ret(2, 0);
        std::unordered_map<int, int> lookup;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 0) {
                ret[1] = i;
                break;
            }
            else if (lookup.find(nums[i]) != lookup.end()) {
                ret[0] = lookup[nums[i]] + 1; // index of the first appearance
                ret[1] = i;
                break;
            }
            else {
                lookup[nums[i]] = i;
            }
        }
        
        return ret;
    }
};