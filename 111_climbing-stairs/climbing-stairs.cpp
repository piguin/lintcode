/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 16-07-28 04:46
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        int dp[2] = { 1, 1 };
        for (int i = 2; i <= n; ++i) {
            dp[i % 2] += dp[(i + 1) % 2];
        }
        return dp[n % 2];
    }
};
