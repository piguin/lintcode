/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 16-07-30 05:53
*/

class Solution {
public:
    int charToInt(char c) {
        return c - '0';    
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        
        int len1 = a.size();
        int len2 = b.size();
        int len = max(len1, len2);
        string c;
        c.resize(len + 1);
        
        int carryOn = 0;
        for (int i = 0; i < len1 || i < len2; ++i) {
            int val;
            if (i >= len1) {
                val = charToInt(b[i]) + carryOn;
            }
            else if (i >= len2) {
                val = charToInt(a[i]) + carryOn;
            }
            else {
                val = charToInt(b[i]) + charToInt(a[i]) + carryOn;
            }
            
            carryOn = val / 2;
            val %= 2;
            c[i] = '0' + val;
        }
        
        if (carryOn > 0) {
            c[len++] = '0' + carryOn;
        }
        c[len] = '\0';
        c.resize(len);
        std::reverse(c.begin(), c.end());
        return c;
    }
};