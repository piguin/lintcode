/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/left-pad
@Language: C++
@Datetime: 16-07-24 19:11
*/

class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar = ' ') {
        int len = originalStr.length();
        size = size > len ? size : len;
        string ret;
        ret.resize(size);

        int pad = size - len;
        for (int i = 0; i < size; ++i) {
            if (i < pad) {
                ret[i] = padChar;
            }
            else {
                ret[i] = originalStr[i - pad];
            }
        }
        
        return ret;
    }
};