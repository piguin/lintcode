/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 16-07-25 00:59
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (target == NULL) return -1;
        if (*target == '\0') return 0;
        if (source == NULL || *source == '\0') return -1;
        
        const char *p = source;
        const char *q = target;
        while (*p != '\0') {
            if (*q == '\0') return p - source - (q - target);
            if (*p == *q) {
                q++;
            }
            else {
                p -= q - target; // wind back
                q = target;
            }
            p++;
        }
        
        if (*q == '\0') return p - source - (q - target);
        return -1;
    }
};
