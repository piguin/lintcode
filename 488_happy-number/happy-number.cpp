/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: C++
@Datetime: 16-07-25 22:03
*/

class Solution {
public:
    vector<int> toDigits(int n) {
        vector<int> ret;
        while (n > 0) {
            ret.push_back(n % 10);
            n /= 10;
        }
        
        return ret;
    }
    
    int squareSum(vector<int> digits) {
        int sum = 0;
        for(auto d : digits) {
            sum += d * d;
        }
        
        return sum;
    }

    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        if (n <= 0) return false;
        
        int x = n;
        vector<int> history;
        while (std::find(history.begin(), history.end(), x) == history.end()) {
            history.push_back(x);
            x = squareSum(toDigits(x));
            if (x == 1) return true;
        }
        
        return false;
    }
};