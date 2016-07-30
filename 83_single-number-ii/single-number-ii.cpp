/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/single-number-ii
@Language: C++
@Datetime: 16-07-24 23:15
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        int len = A.size();
        int one = 0, two = 0, three = 0;
        
        for (int i = 0; i < len; ++i) {
            two = two ^ (one & A[i]); // two holds the bits for elements that appeared twice
            one = one ^ A[i]; // one holds the bits for elements that appeared once
            three = two & one; // three holds bits appeared the 3rd time
            one = one & ~three; // remove the bits if it appeared the 3rd time
            two = two & ~three; // remove the bits if appeared the 3rd time
        }
        
        return one;
    }
};