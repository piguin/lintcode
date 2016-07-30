/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/matrix-zigzag-traversal
@Language: C++
@Datetime: 16-07-30 03:29
*/

class Solution {
public:

    int zigzag(vector<vector<int> > &matrix, int i, int j) {
    	int n = matrix[0].size();
    	if (i >= n) {
    		// cout << "access b: " << i + 1 - n + j << "," << n - 1 - j << endl;
    		return matrix[i + 1 - n + j][n - 1 - j];
    	}
    	// cout << "access a: " << j << "," << i - j << endl;
    	return matrix[j][i - j];
    }
    
    /**
    * @param matrix: a matrix of integers
    * @return: a vector of integers
    */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
    	vector<int> ret;
    	int m = matrix.size();
    	if (m == 0) return ret;
    	int n = matrix[0].size();
    	for (int i = 0; i < m + n - 1; ++i) {
    		int k; // # of integers at zigzag index
    		if (i < std::min(m, n)) k = i + 1;
    		else if (i >= std::min(m, n) && i < std::max(m, n)) k = std::min(m, n);
    		else k = m + n - 1 - i;
    
    		if (i % 2 == 1) {
    			for (int j = 0; j < k; ++j) {
    				ret.push_back(zigzag(matrix, i, j));
    			}
    		}
    		else {
    			for (int j = k - 1; j >= 0; --j) {
    				ret.push_back(zigzag(matrix, i, j));
    			}
    		}
    	}

    	return ret;
    }

};