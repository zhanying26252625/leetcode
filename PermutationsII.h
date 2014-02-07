/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
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
                //previous same item must be used
                if( i>0 && (num[i-1]==num[i] && used[i-1]==false) )
                    continue;
                    
                used[i]=true;
                v.push_back(num[i]);
                permuteHepler(num,used,v);
                used[i]=false;
                v.pop_back(); 
            }
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<int> v;
        vector<bool> used(num.size(),false);
        permuteHepler(num,used,v);
        return retVV;
    }
};