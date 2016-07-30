/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/ugly-number-ii
@Language: C++
@Datetime: 16-07-24 04:33
*/

class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }

    int min(int a, int b, int c) {
        return min(min(a, b), c);
    }

    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; ++i) {
            dp[i] = min(dp[i2] * 2, dp[i3] * 3, dp[i5] * 5);
            if (dp[i] == dp[i2] * 2) ++i2;
            if (dp[i] == dp[i3] * 3) ++i3;
            if (dp[i] == dp[i5] * 5) ++i5;
        }
        
        return dp[n - 1];
    }
};