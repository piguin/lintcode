/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: C++
@Datetime: 16-07-26 04:03
*/

class Solution {
public:
    void swap(char &a, char &b) {
        char tmp = a;
        a = b;
        b = tmp;
    }
    
    void reverse(string &s, int start, int end) {
        int p = start;
        int q = end - 1;
        while (p < q) {
            swap(s[p++], s[q--]);            
        }
    }
    
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // reverse the string
        reverse(s, 0, s.length());
        
        // remove spaces
        int i = 0;
        int j = 0;
        int len = 0;
        while (i < s.length()) {
            if (s[i] == ' ' && (j == 0 || s[j - 1] == ' ')) {
                ++i;
                continue; // skip spaces
            }
            
            s[j++] = s[i++];
        }
        
        // remove trailing space
        if (s[j - 1] == ' ') --j;
        s[j] = '\0';
        s.resize(j);
        
        // reverse the words
        bool inWord = false;
        int p = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (inWord) {
                if (s[i] == ' ') {
                    reverse(s, p, i);
                    p = -1;
                    inWord = false;
                }
            }
            else {
                if (s[i] != ' ') {
                    inWord = true;
                    p = i;
                }
            }
        }
        
        if (p != -1) {
            reverse(s, p, s.length());
        }
        
        return s;
    }
};