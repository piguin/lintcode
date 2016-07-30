/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: C++
@Datetime: 16-07-25 00:35
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        if (n < 2) return 0;
        else if (n == 2) return 1;
        
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n - 1];
    }
};
