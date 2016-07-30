/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 16-07-25 06:08
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> A) {
        int len = A.size();
        int count = 0; int major;
        for (int i = 0; i < len; ++i) {
            if (count == 0) {
                major = A[i];
                ++count;
            }
            else if (A[i] == major) {
                ++count;
            }
            else {
                -- count;
            }
        }
        
        return major;
    }
};
