/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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

    struct MyComp{
        
        bool operator()(const Interval& i1, const Interval& i2){
            return i1.start<i2.start;
        }    
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        
        if(intervals.size()==0||intervals.size()==1)
            return intervals;
            
        sort(intervals.begin(),intervals.end(),MyComp());
        
        vector<Interval> v;
        
        Interval curI = intervals[0];
        
        int index = 1;
        
        while(index<intervals.size()){
            
            Interval newI = intervals[index];
            
            if(newI.start<=curI.end){
                curI.end = max(curI.end, newI.end);
            }
            else{
                v.push_back(curI);
                curI = newI;
            }
            
            ++index;
        }
        
        v.push_back(curI);
        
        return v;
    }
};


/*
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
    struct MyComp{
        
        bool operator()(const Interval& i1, const Interval& i2){
            return i1.start<i2.start;
        }    
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        
        if(intervals.size()==0||intervals.size()==1)
            return intervals;
            
        sort(intervals.begin(),intervals.end(), 
                [](const Interval& i1, const Interval& i2 ){return i1.start<i2.start;} //lamda
            );
        
        vector<Interval> v;
        
        Interval curI = intervals[0];
        
        int index = 1;
        
        while(index<intervals.size()){
            
            Interval newI = intervals[index];
            
            if(newI.start<=curI.end){
                curI.end = max(curI.end, newI.end);
            }
            else{
                v.push_back(curI);
                curI = newI;
            }
            
            ++index;
        }
        
        v.push_back(curI);
        
        return v;
    }
};
*/











