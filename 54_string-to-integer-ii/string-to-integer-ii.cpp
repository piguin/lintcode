/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: C++
@Datetime: 16-07-28 08:08
*/

class Solution {
public:
    int charToDigit(char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        }

        return -1;
    }

    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        int i = 0;
        int sign = 1;

        const int int_max = 0x7fffffff;
        const int int_max_div_by_10 = int_max / 10;
        const int int_max_last_digit = int_max % 10;
        
        const int int_min = 0x80000000;
        const int int_min_div_by_10 = int_min / 10;
        const int int_min_last_digit = int_min % 10;

        while (str[i] == ' ') ++i;

        if (str[i] == '+') {
            ++i;
        }
        else if (str[i] == '-') {
            sign = -1;
            ++i;
        }

        if (str[i] == '\0') return 0;
        int value = charToDigit(str[i++]);
        if (value == -1) return 0;
        value *= sign;

        while (str[i] != '\0') {
            int digit = charToDigit(str[i++]);
            if (digit == -1) break;

            if (sign > 0) {
                int noOverflow = value > int_max_last_digit ? int_max_div_by_10 - 1 : int_max_div_by_10;
                if (value > noOverflow) return int_max;
            }
            else {
                int noOverflow = value < int_min_last_digit ? int_min_div_by_10 + 1 : int_min_div_by_10;
                if (value < noOverflow) return int_min;
            }

            value = value * 10 + sign * digit;
        }

        return value;
    }
};