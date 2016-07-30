/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/reverse-integer
@Language: C++
@Datetime: 16-07-28 08:09
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        if (n == 0) return 0;
        
        vector<int> digits;
        int sign = n < 0 ? -1 : 1;
        
        // convert to negative number, negative number has a larger domain
        n = sign == 1 ? -n : n;
        while (n != 0) {
            digits.push_back( -(n % 10) ); // assuming negative number mod 10 is (10, 0]
            n /= 10;
        }
        
        int len = digits.size();
        int num = sign * digits[0];
        int int_max = sign == 1 ? 0x7fffffff : 0x80000000;
        
        int int_max_div_10 = int_max / 10;
        int int_max_last_digit = sign * (int_max % 10);
        
        for (int i = 1; i < len; ++i) {
            int noOverflow = digits[i] > int_max_last_digit ? int_max_div_10 - sign : int_max_div_10;
            if ((noOverflow - num) * sign < 0) return 0;
            num = num * 10 + sign * digits[i];
        }
        
        return num;
    }
};