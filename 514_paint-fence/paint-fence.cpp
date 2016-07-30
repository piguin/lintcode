/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/paint-fence
@Language: C++
@Datetime: 16-07-30 05:36
*/

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if (n == 0) return 0;
        
        int dp[2];
        dp[0] = 0; // # ways to color so the last two posts are the same
        dp[1] = k; // # ways to color so the last two posts are different
        
        for (int i = 1; i < n; ++i) {
            int a = dp[0];
            int b = dp[1];
            dp[0] = b;
            dp[1] = (a + b) * (k - 1);
        }
        
        return dp[0] + dp[1];
    }
};