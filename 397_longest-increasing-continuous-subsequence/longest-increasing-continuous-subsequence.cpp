/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: C++
@Datetime: 16-07-26 00:34
*/

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
    	if (A.size() == 0) return 0;
    
    	int lenCurr = 1;
    	int lenMax = 0;
    	int dir = 0;
    	int lastNum = A[0];
    	for (int i = 1; i < A.size(); ++i) {
    		int n = A[i];
    		if (dir == 0) {
    			dir = n - lastNum; // dir can only be set when we are after the 1st number
    			lenCurr = (dir != 0) ? 2 : 1;
    		}
    		else if (dir * (n - lastNum) <= 0) { // if dir reversed
    			dir = n - lastNum;
    			lenMax = max(lenMax, lenCurr);
    			lenCurr = (dir != 0) ? 2 : 1;
    		}
    		else {
    			++lenCurr;
    		}
    
    		lastNum = n;
    	}
    	
    	lenMax = max(lenMax, lenCurr);
    	return lenMax;
    }

};