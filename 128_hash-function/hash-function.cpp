/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/hash-function
@Language: C++
@Datetime: 16-07-25 08:31
*/

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        int m = 1;
        int sum = 0;
        for (int i = key.length() - 1; i >= 0; --i) {
            sum += modMultiply(key[i], m, HASH_SIZE);
            sum %= HASH_SIZE;
            m = modMultiply(m, 33, HASH_SIZE);
        }
        
        return sum;
    }
    
    int modMultiply(int a, int b, int mod) {
        long res = (long)a * (long)b;
        return res % mod;
    }
};