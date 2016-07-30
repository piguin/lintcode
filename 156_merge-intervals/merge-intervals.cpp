/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/merge-intervals
@Language: C++
@Datetime: 16-07-30 04:57
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() == 0) return intervals;
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        auto p = ret.begin();
        for (auto q = intervals.begin() + 1; q != intervals.end(); ++q) {
            if (q->start <= p->end) {
                p->end = std::max(p->end, q->end);
            }
            else {
                ret.push_back(*q);
                p = ret.end() - 1;
            }
        }
        
        return ret;
    }
};