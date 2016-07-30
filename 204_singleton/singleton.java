/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/singleton
@Language: Java
@Datetime: 16-07-25 22:34
*/

class Solution {
    private static Object lock = new Object();
    private static Solution _instance = null;
    
    /**
     * @return: The same instance of this class every time
     */
    public static Solution getInstance() {
        if (_instance == null) {
            synchronized(lock) {
                if (_instance == null) {
                    _instance = new Solution();
                }
            }
        }
        
        return _instance;
    }
};