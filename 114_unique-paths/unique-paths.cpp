/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: C++
@Datetime: 16-07-23 17:31
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        
        vector<int> array(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    array[i * n + j] = 1;
                }
                else {
                    array[i * n + j] = array[(i - 1) * n + j] + array[i * n + j - 1];
                }
            }
        }
        
        return array[m * n - 1];
    }
};
