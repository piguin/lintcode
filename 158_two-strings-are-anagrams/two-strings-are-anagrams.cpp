/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 16-07-28 05:26
*/

class Solution {
public:
    void countCharacters(vector<int> &hashMap, string s) {
        for (char c : s) {
            int idx = c - '\0';
            ++hashMap[idx];
        }
    }
    
    bool isEqual(vector<int> const &a, vector<int> const &b) {
        // assuming equal size
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) return false;
        }
        return a.size() == b.size();
    }

    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        vector<int> hashMap1(256, 0);
        vector<int> hashMap2(256, 0);
        countCharacters(hashMap1, s);
        countCharacters(hashMap2, t);
        return isEqual(hashMap1, hashMap2);
    }
};