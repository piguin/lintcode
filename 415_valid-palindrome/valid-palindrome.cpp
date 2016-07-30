/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/valid-palindrome
@Language: C++
@Datetime: 16-07-28 08:33
*/

class Solution {
public:
    bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ;
    }

    int toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return 'a' + c - 'A';
    }

    bool sameAlphaNum(char a, char b) {
        return toLower(a) == toLower(b);
    }

    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        int len = s.size();
        int p = 0;
        int q = len - 1;
        while (p < q) {
            while (p < q && !isAlphaNum(s[p])) ++p; // find the letter
            while (p < q && !isAlphaNum(s[q])) --q;
            if (p < q) {
                if (!sameAlphaNum(s[p++], s[q--])) return false;
            }
        }
        return true;
    }
};