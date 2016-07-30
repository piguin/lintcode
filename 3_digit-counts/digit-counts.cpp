/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/digit-counts
@Language: C++
@Datetime: 16-07-24 08:01
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        if (k == 0 && n == 0) return 1;

        int sum = 0;
        int pow = 1;
        while (pow <= n) {
            int digit = n / pow % 10;
            int left = n / pow / 10;
            int right = n % pow;
            
            if (k == digit) {
                sum += pow * left + right + 1;    
            }
            else if (k < digit) {
                sum += pow * (left + (k == 0 && left == 0 ? 0 : 1));
            }
            else { // k > digit
                sum += pow * left;    
            }
            
            pow *= 10;
        }
        
        return sum;
    }
};