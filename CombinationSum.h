/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution {
public:

    vector<vector<int> > vv;
    
    void combinationSum(vector<int> &candidates, int target, int index, int sum, vector<int>& v){
        
        if(sum==target){
            vv.push_back(v);
            return;
        }
        
        if(sum>target||index>=candidates.size()){
            return;
        }
        
        v.push_back(candidates[index]);
        combinationSum(candidates,target,index,sum+candidates[index],v);
        v.pop_back();
        
        combinationSum(candidates,target,index+1,sum,v);
        
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        combinationSum(candidates,target,0,0,v);
        return vv;
    }
    
};