/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/permutation-index
@Language: C++
@Datetime: 16-07-26 07:51
*/

class Solution {
public:
    // see explanation here http://www.geekviewpoint.com/java/numbers/permutation_index
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        int len = A.size();
        if (len < 2) return 1;
        
        // generate factorial base
        vector<long long> factorial(len - 1);
        long long f = 1;
        for (int i = 1; i < len && i < 20; ++i) { // long long can save at most 20!
            f *= i;
            factorial[len - i - 1] = f;
        }
        
        long long index = 1;
        for (int i = 0; i < len - 1; ++i) {
            // for each i, find how many number after it is smaller than it
            int c = 0;
            for (int j = i + 1; j < len; ++j) {
                if (A[j] < A[i]) ++c;
            }
            
            index += factorial[i] * c;
        }
        
        return index;
    }
};