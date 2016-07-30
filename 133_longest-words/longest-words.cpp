/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: C++
@Datetime: 16-07-25 22:27
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        vector<string> results;
        int longestLen = 0;
        for (auto s : dictionary) {
            if (s.length() > longestLen) {
                results.resize(0); // remove all previously saved strs
                longestLen = s.length();
            }
            // save to the results
            if (s.length() == longestLen) {
                results.push_back(s);
            }
        }
        
        return results;
    }
};