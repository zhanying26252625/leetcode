/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        vector<Interval> newV;
        
        if(intervals.size()==0){
            newV.push_back(newInterval);
            return newV;
        }
        
        int i = 0;
        bool used = false;
        for( ; i < intervals.size(); ++i ){
            Interval& interval = intervals[i];
            if(interval.end < newInterval.start){
                newV.push_back(interval);
            }
            else if(interval.start > newInterval.end){
                used = true;
                newV.push_back(newInterval);
                break;
            }
            else{
                int newStart = min(interval.start, newInterval.start);
                int newEnd = max(interval.end, newInterval.end);
                int j = i+1;
                while( j < intervals.size() ){
                    Interval& interval = intervals[j];
                    if(newEnd>=interval.start){
                        ++j;
                        newEnd = max(interval.end, newEnd);
                    }
                    else{
                        break;
                    }
                }
                
                used = true;
                newV.push_back(Interval(newStart,newEnd));
                i=j;
                break;
            }
        }
        
        if(i<intervals.size()){
            copy(intervals.begin()+i,intervals.end(),back_inserter(newV));
        }
        
        if( used != true){
            newV.push_back(newInterval);
        }
        
        return newV;
    }
    
};