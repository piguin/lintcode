/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 16-07-24 17:21
*/

class Solution {
public:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    template <class Iter>
    void partition(Iter begin, Iter end, Iter pos) {
        Iter p = begin;
        Iter q = end - 1;
        int pivot = *pos;
        while (p != pos) {
            while (*p >= pivot && p != pos) ++p;
            while (*q < pivot && q != pos) --q;
            if (p != pos) {
                swap(*p++, *q--);
            }
        }
    }

    template <class Iter>
    int nthElement(int nth, Iter begin, Iter end) {
        int pivot = *begin;
        Iter pos = begin;
        for (Iter p = begin + 1; p != end; ++p) {
            if (*p >= pivot) ++pos;
        }
        
        int position = pos - begin;
        swap(*pos, *begin);
        partition(begin, end, pos);
        if (nth < position) {
            return nthElement(nth, begin, pos);
        }
        else if (nth > position) {
            return nthElement(nth - position - 1, pos + 1, end);
        } else { // if (nth == position)
            return pivot;
        }
    }
    
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        nthElement(k - 1, nums.begin(), nums.end());
    }
};