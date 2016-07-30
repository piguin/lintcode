/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/update-bits
@Language: C++
@Datetime: 16-07-26 01:22
*/

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
    	// form a mask like 1111110000011, where the index range of the zero hole is [j, i]
    	unsigned int mask;
    	if (j < 31) // left shift 32 is not supported by ia32
    		mask = 0xffffffffu << ++j | ((0x1u << i) - 1);
    	else
    		mask = ((0x1u << i) - 1);
    	 
    	int result = n & mask;
    	result |= m << i;
    	return result;
    }
};