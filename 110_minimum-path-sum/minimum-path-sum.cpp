/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/minimum-path-sum
@Language: C++
@Datetime: 16-07-28 04:32
*/

class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j > 0) grid[i][j] += grid[i][j-1];
                else if (j == 0 && i > 0) grid[i][j] += grid[i-1][j];
                else if (i > 0 && j > 0) grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }
        
        return grid[m - 1][n - 1];
    }
};
