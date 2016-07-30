/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/median
@Language: C++
@Datetime: 16-07-24 00:57
*/

class Solution {
public:
    void swap(int &a, int &b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    void partition(vector<int> &nums, int start, int end, int position) {
        int p = start;
        int q = end - 1;
        int pivot = nums[start + position];
        while (p < start + position) {
            // find a num > pivot, from front
            while (nums[p] <= pivot && p < start + position) ++p;
            // find a num < pivot, from back
            while (nums[q] > pivot && q > start + position) --q;
            if (p != start + position && q != start + position) {
                // swap
                swap(nums[p++], nums[q--]);
            }
        }
    }

    int nthElement(vector<int> &nums, int start, int end, int n) {
        int pivot = nums[start];
        int position = 0;
        for (int i = start + 1; i < end; ++i) {
            if (nums[i] <= pivot) {
                ++position;
            }
        }

        if (position == n) {
            return pivot;
        }

        nums[start] = nums[start + position];
        nums[start + position] = pivot;
        partition(nums, start, end, position);
        if (n < position) {
            return nthElement(nums, start, start + position, n);
        } else {
            return nthElement(nums, start + position + 1, end, n - position - 1);
        }
    }

    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        return nthElement(nums, 0, nums.size(), (nums.size() - 1) / 2);
    }
};
