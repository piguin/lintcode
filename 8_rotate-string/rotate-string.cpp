/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/rotate-string
@Language: C++
@Datetime: 16-07-24 19:00
*/

class Solution {
public:
    void swap(char &a, char &b) {
        char tmp = a;
        a = b;
        b = tmp;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        int len = str.length();
        int outerLoops = gcd(len, offset);
        int innerLoops = len / outerLoops;
        
        for (int i = 0; i < outerLoops; ++i) {
            int currIndex = i;
            char charToRotate = str[currIndex];
            for (int j = 0; j < innerLoops; ++j) {
                currIndex = (currIndex + offset) % len;
                swap(str[currIndex], charToRotate);
            }
        }
    }
};
