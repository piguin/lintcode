/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/sort-letters-by-case
@Language: C++
@Datetime: 16-07-24 19:46
*/

class Solution {
public:
    bool isLowerCase(char c) {
        // assuming ASCII
        return c <= 'z' && c >= 'a';
    }
    void swap(char &a, char &b) {
        char tmp = a;
        a = b;
        b = tmp;
    }
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        int position = 0;
        for (int i = 0; i < letters.length(); ++i) {
            if (isLowerCase(letters[i])) ++position;
        }
        
        // partition
        int p = 0;
        int q = letters.length() - 1;
        while (p != position) {
            while (p < position && isLowerCase(letters[p])) ++p;
            while (q >= position && !isLowerCase(letters[q])) --q;
            if (p < position && q >= position) {
                swap(letters[p], letters[q]);
            }
        }
    }
};
