/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays
@Language: C++
@Datetime: 16-07-30 04:21
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> valueMap;
        for (int n : nums1) valueMap[n] = 1;
        for (int n : nums2) {
            if (valueMap.find(n) != valueMap.end()) valueMap[n] = -1;
        }
        
        vector<int> ret;
        for (auto &kv : valueMap) {
            if (kv.second == -1)  ret.push_back(kv.first);
        }
        return ret;
    }
};