/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: C++
@Datetime: 16-07-27 06:24
*/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    int get(vector<Interval> &intervals, int i) {
        return (i % 2 == 0) ? intervals[i / 2].start : intervals[i / 2].end;
    }

    int findIndex(vector<Interval> &intervals, int target) {
        int len = intervals.size();
        int lower = 0;
        int upper = 2 * len - 1;
        if (target > get(intervals, upper)) return upper + 1;
        while (lower < upper) {
            int middle = lower + (upper - lower) / 2;
            if (target > get(intervals, middle)) {
                lower = middle + 1;
            } else {
                upper = middle;
            }
        }
        
        return lower; // this is the index;
    }
    
    template <class Iter>
    void safeErase(vector<Interval> &intervals, Iter start, Iter end) {
    	if (start != intervals.end() && start < end)
    		intervals.erase(start, end);
    }
    
    /**
    * Insert newInterval into intervals.
    * @param intervals: Sorted interval list.
    * @param newInterval: new interval.
    * @return: A new interval list.
    */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	int len = intervals.size();
    	if (len == 0) {
    		intervals.push_back(newInterval);
    		return intervals;
    	}
    
    	int i1 = findIndex(intervals, newInterval.start);
    	int i2 = findIndex(intervals, newInterval.end);
    	int startIntervalIdx = i1 / 2;
    	int endIntervalIdx = i2 / 2;
    	bool startInside = startIntervalIdx < len && intervals[startIntervalIdx].start <= newInterval.start && intervals[startIntervalIdx].end >= newInterval.start;
    	bool endInside = endIntervalIdx < len && intervals[endIntervalIdx].start <= newInterval.end && intervals[endIntervalIdx].end >= newInterval.end;
    
    	auto removeStart = intervals.begin() + startIntervalIdx;
    	auto removeEnd = intervals.begin() + endIntervalIdx;
    
    	if (startInside && endInside) {
    		if (startIntervalIdx != endIntervalIdx) {
    			intervals[startIntervalIdx].end = intervals[endIntervalIdx].end;
    			safeErase(intervals, removeStart + 1, removeEnd + 1);
    		}
    	}
    	else if (!startInside && !endInside) {
    		safeErase(intervals, removeStart, removeEnd);
    		intervals.insert(intervals.begin() + startIntervalIdx, newInterval);
    	}
    	else if (startInside) {
    		intervals[startIntervalIdx].end = newInterval.end;
    		safeErase(intervals, removeStart + 1, removeEnd);
    	}
    	else if (endInside) {
    		intervals[endIntervalIdx].start = newInterval.start;
    		safeErase(intervals, removeStart, removeEnd);
    	}
    	return intervals;
    }
};