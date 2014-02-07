/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:

    vector<vector<int> > retVV;
    
    void permuteHepler(vector<int> &num ,vector<bool>& used, vector<int>& v) {
        if(v.size() == num.size()){
            retVV.push_back(v);
            return;
        }
        
        for(int i = 0; i < num.size(); ++i){
            if( ! used[i] ){
                used[i]=true;
                v.push_back(num[i]);
                permuteHepler(num,used,v);
                used[i]=false;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<int> v;
        vector<bool> used(num.size(),false);
        permuteHepler(num,used,v);
        return retVV;
    }
    
};