/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:

    unordered_map<int,bool> cache;
    //recursive
    bool canJump(const vector<int>& v, int curPos){
        
        if(curPos>=v.size()-1)
            return true;
            
        if(cache.count(curPos))
            return cache[curPos];
        
        int len = v[curPos];
        for(int i = 1; i<len; ++i){
            if(canJump(v,curPos+i)){
                cache[curPos]=true;
                return true;
            }
        }
        
        cache[curPos]=false;
        return false;
    }
    
    bool canJump(int A[], int n) {
        vector<int> v(A,A+n);
        //return canJump(v,0);
        //return canJump2(v);
        return canJump3(v);
    }
    
    //iterative
    bool canJump2(const vector<int>& v){
        vector<bool> reach(v.size(),false);
        reach[0]=true;
        for(int i = 0; i < v.size(); ++i){
            if(reach[i]){
                int len = v[i];
                for(int j = 1; j < len; ++j){
                    reach[i+j]=true;
                    if(i+j==v.size()-1)
                        return true;
                }
            }
        }
        
        return reach[v.size()-1];
    }
    
    //fast
    bool canJump3(const vector<int>& v){
        int start = 0, end = 0;
        while (start <= end) {
            end = max(end, start+v[start]);
            if (end >= v.size()-1) return true;
            start++;
        }
        return false;
    }
        
};

