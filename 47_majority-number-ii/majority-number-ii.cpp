/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 16-07-25 06:13
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> A) {
        int len = A.size();
        int count = 0;
        int major;
        for (int i = 0; i < len; ++i) {
            if (count == 0) {
                major = A[i];
                count = 3;
            }
            else if (major == A[i]) {
                count += 2;
            }
            else {
                --count;
            }
        }
        
        return major;
    }
};
