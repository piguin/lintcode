/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 16-07-26 04:27
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int upper = A.size();
        int lower = 0;
        
        while (lower < upper - 1) {
            int middle = (lower + upper) / 2;
            if (target == A[middle]) {
                return middle;
            } else if (target < A[middle]) {
                upper = middle;
            } else {
                lower = middle;   
            }
        }
        
        if (upper > 0 && target <= A[lower]) return lower;
        return upper;
    }
};