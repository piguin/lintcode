/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: C++
@Datetime: 16-07-25 22:48
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        if (str.length() > 256) return false;
        vector<bool> flags(256, false);
        for (auto c : str) {
            int idx = c - '\0';
            if (flags[idx]) return false;
            flags[idx] = true;
        }
        
        return true;
    }
};