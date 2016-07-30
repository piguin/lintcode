/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 16-07-23 18:09
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(),column = obstacleGrid[0].size();
        vector<int> dp(column,0);
        dp[0] = 1;
        for (int i = 0;i < row;++i)
            for (int j = 0;j < column;++j) {
                dp[j] = obstacleGrid[i][j]==1?0:j==0?dp[j]^obstacleGrid[i][j]:dp[j]+dp[j-1];
            }
        return dp[column-1];
    }

};