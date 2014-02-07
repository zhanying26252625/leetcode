/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6]
*/


class Solution {
public:

    vector<vector<int> > vv;
    
    void combinationSum(vector<int> &candidates, int target, int index, int sum, 
                        vector<int>& v ,vector<bool>& used){
        
        if(sum==target){
            vv.push_back(v);
            return;
        }
        
        if(sum>target||index>=candidates.size()){
            return;
        }
        
        //previous same ones must be used if it exists
        bool flag = true;
        
        if( index!=0 && (candidates[index-1]==candidates[index] && used[index-1]==false ) ){
            flag = false;//previous same one is not used
        }
        
        if(flag){
            v.push_back(candidates[index]);
            used[index]=true;
            combinationSum(candidates,target,index+1,sum+candidates[index],v,used);
            v.pop_back();
            used[index]=false;
        }

        combinationSum(candidates,target,index+1,sum,v,used);
    }
    
    vector<vector<int> > combinationSum2(vector<int> & num, int target) {
        
        sort(num.begin(),num.end());
        vector<int> v;
        vector<bool> used(num.size(),false);
        combinationSum(num,target,0,0,v,used);
        return vv;
    }
    
};