/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/valid-parentheses
@Language: C++
@Datetime: 16-07-25 22:59
*/

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        vector<char> stack;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            }
            if (c == ')' || c == '}' || c == ']') {
                if (stack.size() == 0) return false;
                if (c == ')' && stack.back() != '(') return false;
                if (c == '}' && stack.back() != '{') return false;
                if (c == ']' && stack.back() != '[') return false;
                stack.pop_back();
            }  
        }
        
        return stack.size() == 0;
    }
};