/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/recover-rotated-sorted-array
@Language: C++
@Datetime: 16-07-27 07:23
*/

class Solution {
public:
    int swap(int &a, int &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    int min(int a, int b) {
        return a < b ? a : b;
    }
    
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    
    void recoverRotatedSortedArray(vector<int> &nums) {
        // find min
        int len = nums.size();
        int minNum = nums[0];
        int minIndex = 0;
        for (int i = 1; i < len; ++i) {
            if (minNum > nums[i]) {
                minNum = nums[i];
                minIndex = i;
            }
        }
        
        if (minIndex == 0) return;
        int outerLoop = gcd(len, minIndex);
        int innerLoop = len / outerLoop - 1;
        
        for (int i = 0; i < outerLoop; ++i) {
            int p = i;
            for (int j = 0; j < innerLoop; ++j) {
                p = (p + len - minIndex) % len;
                swap(nums[i], nums[p]);
            }
        }
    }
};