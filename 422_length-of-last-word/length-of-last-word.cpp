/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: C++
@Datetime: 16-07-25 22:12
*/

class Solution {
public:
    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int len = 0;
        bool isInWord = false;
        for (auto c : s) {
            if (isInWord) {
                if (isAlpha(c)) {
                    ++len;
                }
                else {
                    len = 0;
                    isInWord = false;
                }
            }
            else {
                if (isAlpha(c)) {
                    ++len;
                    isInWord = true;
                }
            }
        }
        return len;
    }
};