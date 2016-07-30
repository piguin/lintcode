/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 16-07-27 03:22
*/

class Solution {
public:
    int& get(vector<vector<int> > &matrix, int index) {
        // assum size != is checked outside
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        return matrix[index / numCols][index % numCols];
    }

    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) return false;
        int len = matrix.size() * matrix[0].size();
        if (target < get(matrix, 0) || target > get(matrix, len - 1)) return false;
        
        int lower = 0;
        int upper = len - 1;
        while (lower < upper) {
            int middle = (lower + upper) / 2;
            if (get(matrix, middle) < target) lower = middle + 1;
            else upper = middle;
        }
        return get(matrix, lower) == target;
    }
};
