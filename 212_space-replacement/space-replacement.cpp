/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: C++
@Datetime: 16-07-26 03:36
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // first pass count # of spaces
        int numSpaces = 0;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ') ++numSpaces;
        }
        
        // second pass reverse copy
        int i = length - 1;
        int j = length + numSpaces * 2 - 1;
        while (i >= 0) {
            if (string[i] == ' ') {
                string[j - 2] = '%';
                string[j - 1] = '2';
                string[j] = '0';
                j -= 3;
                --i;
            }
            else {
                string[j--] = string[i--];    
            }
        }
        
        return length + numSpaces * 2;
    }
};  