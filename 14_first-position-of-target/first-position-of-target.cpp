/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 16-07-24 20:41
*/

class Solution {
public:

    template <class Iter>
    Iter binarySearch(Iter begin, Iter end, int target) {
        if (begin == end) return end;
    
        Iter half = begin + (end - begin - 1) / 2;
    
        // search in left
        Iter foundLeft = binarySearch(begin, half, target);
        if (foundLeft != half) {
            return foundLeft; // found
        }
    
        // if not found in left, but the target is smaller than *half
        if (target < *half) {
            return end; // not found
        }
        else if (target == *half) {
            return half; // only return when target if not found in left
        }
    
        // target > *half
    
        // search in right
        Iter foundRight = binarySearch(half + 1, end, target);
        if (foundRight != end) {
            return foundRight; // found
        }
    
        return end;
    }
    
    /**
    * @param nums: The integer array.
    * @param target: Target number to find.
    * @return: The first position of target. Position starts from 0.
    */
    int binarySearch(vector<int> &array, int target) {
        auto found = binarySearch(array.begin(), array.end(), target);
        return found == array.end() ? -1 : (found - array.begin());
    }

};