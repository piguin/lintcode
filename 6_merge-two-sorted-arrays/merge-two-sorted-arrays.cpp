/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-arrays
@Language: C++
@Datetime: 16-07-25 00:30
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> ret(A.size() + B.size());
        auto p = A.begin();
        auto q = B.begin();
        auto r = ret.begin();
        while (p != A.end() || q != B.end()) {
            if (q != B.end() && (p == A.end() || *p >= *q)) *r++ = *q++;
            else if (p != A.end() && (q == B.end() || *p < *q)) *r++ = *p++;
        }
        return ret;
    }
};