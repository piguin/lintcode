/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/sort-integers-ii
@Language: C++
@Datetime: 16-07-26 06:44
*/

class Solution {
public:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void heapSort(vector<int>& A) {
        int len = A.size();
        int nonLeafNode = len / 2 - 1;
        while (nonLeafNode >= 0) heapify(A, nonLeafNode--, len);
        
        for (int p = len - 1; p > 0; --p) {
            swap(A[0], A[p]);
            heapify(A, 0, p);
        }
    }
    
    void heapify(vector<int>& A, int start, int end) {
        int root = start;
        
        while (true) {
            int child = 2 * root + 1; // left node
            if (child >= end) break;
            if (child + 1 < end && A[child] < A[child + 1]) {
                child = child + 1;
            }
            if (A[root] < A[child]) {
                swap(A[root], A[child]);
                root = child;
            }
            else {
                break;
            }
        }
    }

    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        heapSort(A);
    }
};