/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/cosine-similarity
@Language: C++
@Datetime: 16-07-26 07:25
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        if (A.size() != B.size() || A.size() == 0) return 2.0;

        int len = A.size();
        double m = 0, d1 = 0, d2 = 0;

        for (int i = 0; i < len; ++i) {
            m += (double)A[i] * B[i];
            d1 += (double)A[i] * A[i];
            d2 += (double)B[i] * B[i];
        }
        
        if (d1 == 0.0 || d2 == 0.0) return 2.0;
        
        d1 = std::sqrt(d1);
        d2 = std::sqrt(d2);
        return m / d1 / d2;
    }
};
