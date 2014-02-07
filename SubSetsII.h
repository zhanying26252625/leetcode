/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    void subsets(vector<int> &S, int index, vector<int>& v, 
    			 vector<vector<int> >& vv, vector<bool>& used) {

		vv.push_back(v);

		if(index < S.size()){
			for(int i = index; i < S.size(); ++i){
				//make sure previous same one must be used
				if(i>0&&S[i-1]==S[i]&&used[i-1]==false)
					continue;

				v.push_back(S[i]);
				used[i]=true;
				subsets(S,i+1,v,vv,used);
				v.pop_back();
				used[i]=false;
			}
		}
	}

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > vv;
        vector<int> v;
        vector<bool> used(S.size(),false);
        sort(S.begin(),S.end());
        subsets(S,0,v,vv,used);
        return vv;
    }
};