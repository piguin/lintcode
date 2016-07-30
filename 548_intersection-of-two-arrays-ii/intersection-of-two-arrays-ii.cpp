/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays-ii
@Language: C++
@Datetime: 16-07-30 04:39
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> valueMap1;
        for (int n : nums1) {
            if (valueMap1.find(n) != valueMap1.end()) ++valueMap1[n];
            else valueMap1[n] = 1;
        }
        
        std::unordered_map<int, int> valueMap2;
        for (int n : nums2) {
            // if this number doesn't appear in the first array, don't bother
            if (valueMap1.find(n) != valueMap1.end()) {
                if (valueMap2.find(n) != valueMap2.end()) {
                    if (valueMap2[n] < valueMap1[n]) {
                        ++valueMap2[n];
                    }
                }
                else {
                    valueMap2[n] = 1;
                }
            }
        }
        
        vector<int> ret;
        for (auto &kv : valueMap2) {
            int n = kv.first;
            for (int i = 0; i < kv.second; ++i) {
                ret.push_back(n);
            }
        }
        return ret;
    }
};