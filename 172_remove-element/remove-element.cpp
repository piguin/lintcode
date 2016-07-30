/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 16-07-23 16:16
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int q = 0;
        for (int p = 0; p < A.size(); ++p) {
            if (A[p] == elem) {
                continue;
            }
            else {
                A[q++] = A[p];
            }
        }
        
        return q;
    }
};