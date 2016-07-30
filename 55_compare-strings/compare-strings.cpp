/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 16-07-24 19:35
*/

class Solution {
public:
    int charToIndex(char c) {
        // assuming ASCII
        if (c >= 'A' && c <= 'Z') return c - 'A';
        return 26;
    }

    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        vector<int> charOccurs(27); // one extra for invalid character count
        
        // get char count from A
        for (int i = 0; i < A.length(); ++i) {
            ++charOccurs[charToIndex(A[i])];
        }
        // remove chars from B
        for (int i = 0; i < B.length(); ++i) {
            --charOccurs[charToIndex(B[i])];
        }
        
        // A contains all chars in B iff charOccurs is all above 0
        for (int i = 0; i < 26; ++i) {
            if (charOccurs[i] < 0) return false;
        }
        
        return true;
    }
};
