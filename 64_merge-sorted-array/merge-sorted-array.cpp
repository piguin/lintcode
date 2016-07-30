/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/merge-sorted-array
@Language: C++
@Datetime: 16-07-27 07:59
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        if (n == 0) return;
        
        // find the first element in A which is larger than B[0]
        int p;
        for (p = 0; p < m; ++p) {
            if (A[p] > B[0]) break;
        }
        
        // move A[p:] towards the end, have to use reverse copy
        for (int i = m - 1; i >= p; --i) {
            A[i + n] = A[i];
        }
        
    	// now insert which ever is smaller from A[i] and B[j]
    	int i = p + n;
    	int j = 0;
    	while (i < m + n && j < n) {
    		if (A[i] < B[j])
    			A[p++] = A[i++];
    		else
    			A[p++] = B[j++];
    	}
    
    	// while (i < m + n) A[p++] = A[i++];
    	while (j < n) A[p++] = B[j++];
    }
};