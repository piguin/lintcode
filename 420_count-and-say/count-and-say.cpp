/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/count-and-say
@Language: C++
@Datetime: 16-07-28 06:37
*/

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            stringstream ss;
            for (int j = 0; j < s.length(); ++j) {
                int count = 1;
                for (;s[j] == s[j+1]; ++j) ++count;
                ss << count << s[j];
            }
            s = ss.str();
        }
        return s;
    }
};