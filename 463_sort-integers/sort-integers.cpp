/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/sort-integers
@Language: C++
@Datetime: 16-07-24 21:30
*/

class Solution {
public:

    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void selectionSort(vector<int> &A) {
        int len = A.size();
        for (int i = 0; i < len; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < len; ++j) {
                minIdx = A[minIdx] < A[j] ? minIdx : j;
            }
            swap(A[i], A[minIdx]);
        }
    }
    
    void bubbleSort(vector<int> &A) {
        int len = A.size();
        for (int i = 0; i < len; ++i) {
            int numSwaps = 0;
            for (int j = 0; j < len - i - 1; ++j) {
                if (A[j] > A[j + 1]) {
                    swap(A[j], A[j + 1]);
                    ++numSwaps;
                }
            }
            if (numSwaps == 0) break;
        }
    }

    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // selectionSort(A);
        bubbleSort(A);
    }
};
