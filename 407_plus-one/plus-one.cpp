/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: C++
@Datetime: 16-07-25 08:04
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0) return digits;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};